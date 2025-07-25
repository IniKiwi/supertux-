//  SuperTux
//  Copyright (C) 2015 Ingo Ruhnke <grumbel@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <errno.h>
#include <string.h>
#include <cassert>
#include <sstream>

#include "addon/md5.hpp"

int main(int argc, char** argv)
{
  std::istringstream empty("");
  assert(std::string("d41d8cd98f00b204e9800998ecf8427e") == std::string(MD5(empty).hex_digest()));

  std::istringstream helloworld("HelloWorld");
  assert(std::string("68e109f0f40ca72a15e05cc22786f8e6") == std::string(MD5(helloworld).hex_digest()));
}

/* EOF */
