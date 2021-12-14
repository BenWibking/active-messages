#ifndef BUFFER_HPP_ // NOLINT
#define BUFFER_HPP_
//==============================================================================
// ActiveMessages
// Copyright 2021 Benjamin Wibking.
// Released under the MIT license. See LICENSE file included in the GitHub repo.
//==============================================================================
/// \file buffer.hpp
///

// non-owning buffer object pointing to arbitrary bytes
class Buffer {
  void *buffer;
  std::size_t size;

public:
  Buffer(void *buf, std::size_t s) : buffer(buf), size(s) {}
};

#endif // BUFFER_HPP_