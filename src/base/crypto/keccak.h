/* XMRig
 * Copyright (c) 2011      Markku-Juhani O. Saarinen <mjos@iki.fi>
 * Copyright (c) 2018-2021 SChernykh                 <https://github.com/SChernykh>
 * Copyright (c) 2016-2021 XMRig                     <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef XMRIG_KECCAK_H
#define XMRIG_KECCAK_H

#include <cstdint>
#include <cstring>


namespace xmrig {

// compute a keccak hash (md) of given byte length from "in"
void keccak(const uint8_t *in, int inlen, uint8_t *md, int mdlen);


inline void keccak(const uint8_t *in, size_t inlen, uint8_t *md)
{
    keccak(in, static_cast<int>(inlen), md, 200);
}


inline void keccak(const char *in, size_t inlen, uint8_t *md)
{
    keccak(reinterpret_cast<const uint8_t *>(in), static_cast<int>(inlen), md, 200);
}

// update the state
void keccakf(uint64_t st[25], int norounds);

} /* namespace xmrig */

#endif /* XMRIG_KECCAK_H */
