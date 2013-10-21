/*
 * Copyright 2012-2013 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// C++ standard includes
#include <string.h> // for memcpy
#include <algorithm>

// libfalltergeist includes
#include "../src/DatFileItem.h"
#include "../src/DatFileEntry.h"
#include "../src/DatFile.h"

// Third party includes
#include "zlib.h"


namespace libfalltergeist
{

DatFileItem::DatFileItem(std::ifstream * stream)
{
    _asMap = 0;

    _buffer = 0;
    _initialized = false;
    _stream = stream;
    _datFileEntry = 0;
}


DatFileItem::DatFileItem(DatFileEntry * datFileEntry)
{
    _asMap = 0;

    _buffer = 0;
    _initialized = false;
    _stream = 0;
    _datFileEntry = datFileEntry;

    setFilename(datFileEntry->filename());


}

void DatFileItem::_initialize()
{
    if (_initialized) return;

    _initialized = true;

    if (_stream != 0)
    {
        _stream->seekg(0, std::ios::end);
        _size = _stream->tellg();
        _stream->seekg(0, std::ios::beg);

        _buffer = new char[_size];
        _stream->readsome(_buffer, _size);
        _stream->close();
        setg(_buffer, _buffer, _buffer + _size);
        return;
    }

    if (_datFileEntry != 0)
    {
        _buffer = new char[_datFileEntry->unpackedSize()];
        _size = _datFileEntry->unpackedSize();

        DatFile * datFile = _datFileEntry->datFile();
        unsigned int oldPos = datFile->position();
        datFile->setPosition(_datFileEntry->dataOffset());

        if (_datFileEntry->compressed())
        {
            char * packedData = new char[_datFileEntry->packedSize()]();
            datFile->readBytes(packedData, _datFileEntry->packedSize());

            // unpacking
            z_stream zStream;
            zStream.total_in  = zStream.avail_in  = _datFileEntry->packedSize();
            zStream.avail_in = _datFileEntry->packedSize();
            zStream.next_in  = (unsigned char *)packedData;
            zStream.total_out = zStream.avail_out = _size;
            zStream.next_out = (unsigned char *)_buffer;
            zStream.zalloc = Z_NULL;
            zStream.zfree = Z_NULL;
            zStream.opaque = Z_NULL;
            inflateInit( &zStream );            // zlib function
            inflate( &zStream, Z_FINISH );      // zlib function
            inflateEnd( &zStream );             // zlib function

            delete [] packedData;
        }
        else
        {
            // just copying from dat file
            datFile->readBytes(_buffer, _size);
        }

        datFile->setPosition(oldPos);
        setg(_buffer, _buffer, _buffer + _size);
        return;

    }
}


DatFileItem::~DatFileItem()
{
    delete _asMap;

    delete [] _buffer;
}

unsigned int DatFileItem::size()
{
    return _size;
}

std::streambuf::int_type DatFileItem::underflow()
{
    _initialize();
    if (gptr() == egptr())
    {
        return traits_type::eof();
    }
    return traits_type::to_int_type(*gptr());
}

void DatFileItem::setFilename(const std::string filename)
{
    _filename = filename;

    // convert to lowercase and replace slashes
    std::replace(_filename.begin(),_filename.end(),'\\','/');
    std::transform(_filename.begin(),_filename.end(),_filename.begin(), ::tolower);
}

std::string DatFileItem::filename()
{
    return _filename;
}

void DatFileItem::setPosition(unsigned int pos)
{
    _initialize();
    setg(_buffer, _buffer + pos, _buffer + _size);
}

unsigned int DatFileItem::position()
{
    _initialize();
    return gptr() - eback();
}

void DatFileItem::skipBytes(unsigned int numberOfBytes)
{
    _initialize();
    setg(_buffer, gptr() + numberOfBytes, _buffer + _size);
}

void DatFileItem::readBytes(char * destination, unsigned int size)
{
    _initialize();
    sgetn(destination, size);
}


DatFileItem& DatFileItem::operator>>(unsigned int &value)
{
    _initialize();
    char * buff = reinterpret_cast<char *>(&value);
    sgetn(buff, sizeof(value));
    std::reverse(buff, buff + sizeof(value));
    return *this;
}

DatFileItem& DatFileItem::operator>>(int &value)
{
    return *this >> (unsigned int&) value;
}

DatFileItem& DatFileItem::operator>>(unsigned short &value)
{
    _initialize();
    char * buff = reinterpret_cast<char *>(&value);
    sgetn(buff, sizeof(value));
    std::reverse(buff, buff + sizeof(value));
    return *this;
}

DatFileItem& DatFileItem::operator>>(short &value)
{
    return *this >> (unsigned short&) value;
}

DatFileItem& DatFileItem::operator>>(unsigned char &value)
{
    _initialize();
    sgetn(reinterpret_cast<char *>(&value), sizeof(value));
    return *this;
}

DatFileItem& DatFileItem::operator>>(char &value)
{
    return *this >> (unsigned char&) value;
}

MapFileType * DatFileItem::asMapFileType(ProFileTypeLoaderCallback callback)
{
    if (_asMap) return _asMap;
    _asMap = new MapFileType(this, callback);
    return _asMap;
}

}
