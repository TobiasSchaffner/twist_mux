/*********************************************************************
 * Software License Agreement (CC BY-NC-SA 4.0 License)
 *
 *  Copyright (c) 2014, PAL Robotics, S.L.
 *  All rights reserved.
 *
 *  This work is licensed under the Creative Commons
 *  Attribution-NonCommercial-ShareAlike 4.0 International License.
 *
 *  To view a copy of this license, visit
 *  http://creativecommons.org/licenses/by-nc-sa/4.0/
 *  or send a letter to
 *  Creative Commons, 444 Castro Street, Suite 900,
 *  Mountain View, California, 94041, USA.
 *********************************************************************/

/*
 * @author Enrique Fernandez
 */

#ifndef TWIST_MUX_DIAGNOSTICS_STATUS_H
#define TWIST_MUX_DIAGNOSTICS_STATUS_H

#include <ackermann_mux/ackermann_mux.h>
#include <ackermann_mux/topic_handle.h>

#include <ros/time.h>

namespace ackermann_mux
{

struct AckermannMuxDiagnosticsStatus
{
  typedef boost::shared_ptr<AckermannMuxDiagnosticsStatus> Ptr;
  typedef boost::shared_ptr<const AckermannMuxDiagnosticsStatus> ConstPtr;

  double reading_age;
  ros::Time last_loop_update;
  double main_loop_time;

  LockTopicHandle::priority_type priority;

  boost::shared_ptr<AckermannMux::velocity_topic_container> velocity_hs;
  boost::shared_ptr<AckermannMux::lock_topic_container>     lock_hs;

  AckermannMuxDiagnosticsStatus()
    : reading_age(0),
      last_loop_update(ros::Time::now()),
      main_loop_time(0),
      priority(0)
  {
  }
};

typedef AckermannMuxDiagnosticsStatus::Ptr      AckermannMuxDiagnosticsStatusPtr;
typedef AckermannMuxDiagnosticsStatus::ConstPtr AckermannMuxDiagnosticsStatusConstPtr;

} // namespace ackermann_mux

#endif // TWIST_MUX_DIAGNOSTICS_STATUS_H
