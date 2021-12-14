#ifndef ACTIVE_MESSAGE_HPP_ // NOLINT
#define ACTIVE_MESSAGE_HPP_
//==============================================================================
// ActiveMessages
// Copyright 2021 Benjamin Wibking.
// Released under the MIT license. See LICENSE file included in the GitHub repo.
//==============================================================================
/// \file active_messages.hpp
///

#include <cstddef>
#include <functional>
#include <list>

#include <mpi.h>

#include "buffer.hpp"
#include "active_communicator.hpp"

class ActiveMessage {
  ActiveCommunicator &comm;
  Buffer buf;
  std::function<void(Buffer)> userTask;
  int source_rank;
  int dest_rank;

public:
  ActiveMessage(std::function<void(Buffer)> f, Buffer b, int dest,
                ActiveCommunicator &c)
      : buf(b), userTask(f), source_rank(c.this_rank()), dest_rank(dest),
        comm(c) {}
};

#endif // ACTIVE_MESSAGE_HPP_
