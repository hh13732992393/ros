/*
 * Copyright (C) 2009, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROSCPP_SINGLE_SUBSCRIBER_PUBLISHER_H
#define ROSCPP_SINGLE_SUBSCRIBER_PUBLISHER_H

#include "ros/forwards.h"
#include "ros/message.h"

#include <boost/utility.hpp>

namespace ros
{

/**
 * \brief Allows publication of a message to a single subscriber. Only available inside subscriber connection callbacks
 */
class SingleSubscriberPublisher : public boost::noncopyable
{
public:
  SingleSubscriberPublisher(const SubscriberLinkPtr& link);
  ~SingleSubscriberPublisher();

  /**
   * \brief Publish a message on the topic associated with this Publisher.
   *
   * This version of publish will allow fast intra-process message-passing in the future,
   * so you may not mutate the message after it has been passed in here (since it will be
   * passed directly into a callback function)
   *
   */
  void publish(const Message::ConstPtr& message) const;
  /**
   * \brief Publish a message on the topic associated with this Publisher.
   */
  void publish(const Message& message) const;

  /**
   * \brief Returns the topic this publisher publishes on
   */
  std::string getTopic() const;

  /**
   * \deprecated in favor of getSubscriberName()
   */
  ROSCPP_DEPRECATED std::string getSubscriberCallerID() const;

  /**
   * \brief Returns the name of the subscriber node
   */
  std::string getSubscriberName() const;

private:

  SubscriberLinkPtr link_;
};

}

#endif // ROSCPP_PUBLISHER_HANDLE_H

