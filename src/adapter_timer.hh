/*
 * fMBT, free Model Based Testing tool
 * Copyright (c) 2011, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#include "adapter.hh"
#include <sys/time.h>

class Adapter_timer: public Adapter {
public:
  Adapter_timer(Log& l, std::string params);
  virtual void execute(std::vector<int>& action);
  virtual bool observe(std::vector<int> &action,bool block=false);
  virtual std::string stringify();
  virtual void set_actions(std::vector<std::string>* _actions);
  virtual bool init() {
    return true;
  }
private:
  std::vector<struct timeval> timeout;
  struct action_timeout {
    int timer;
    struct timeval time;
  };
  std::vector<struct action_timeout> atime; // atime[action]
  std::vector<int> enabled; 
  std::vector<int> expire_map;
};