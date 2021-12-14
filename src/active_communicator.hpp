#ifndef ACTIVE_COMMUNICATOR_HPP_ // NOLINT
#define ACTIVE_COMMUNICATOR_HPP_
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

// forward declarations
class Buffer;
class ActiveMessage;

// wraps an MPI_Communicator and provides a method to create new active messages
class ActiveCommunicator {
  MPI_Comm comm = MPI_COMM_WORLD;

  // messages ready to be sent
  std::list<ActiveMessage> send_queue;
  // messages that are being (asynchronously) sent
  std::list<ActiveMessage> send_progress_queue;
  // messages that are being (asynchronously) received
  std::list<ActiveMessage> receive_progress_queue;

public:
  auto newMessage(std::function<void(Buffer)> f, Buffer buf, int dest_rank)
      -> ActiveMessage;
  
  inline int this_rank() {
    int rank;
    MPI_Comm_rank(comm, &rank);
    return rank;
  }
};

#endif // ACTIVE_COMMUNICATOR_HPP_
