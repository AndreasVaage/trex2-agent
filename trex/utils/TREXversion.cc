/*********************************************************************
 * Software License Agreement (BSD License)
 * 
 *  Copyright (c) 2011, MBARI.
 *  All rights reserved.
 * 
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 * 
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the TREX Project nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */
#include "TREXversion.hh"
#include <trex/version.hh>

#include <sstream>

#ifdef WITH_GIT_TRACK
# include "git/version.hh"
#else
// Make the default dimilar to when we do not find svn
# define GIT_INFO   false
# define GIT_BRANCH "unknown"
# define GIT_REV    "exported"
#endif 

unsigned short TREX::version::major() {
  return TREX_MAJOR;
}

unsigned short TREX::version::minor() {
  return TREX_MINOR;
}

unsigned short TREX::version::release() {
  return TREX_PATCH;
}

bool TREX::version::is_release_candidate() {
  return rc_number()>0;
}

unsigned TREX::version::rc_number() {
  return TREX_RC;
}


unsigned long TREX::version::number() {
  unsigned long version = major();
  version = 100*version + minor();
  version = 100*version + release();
  return version;
}

std::string TREX::version::str() {
  return TREX_VERSION;
}

bool TREX::version::svn_info() {
  return false;
}

std::string TREX::version::svn_root() {
  return std::string();
}

std::string TREX::version::svn_revision() {
  return std::string();
}

bool TREX::version::git_info() {
  return GIT_INFO;
}

std::string TREX::version::git_branch() {
  return GIT_BRANCH;
}

std::string TREX::version::git_revision() {
  return GIT_REV;
}

std::string TREX::version::full_str() {
  if( git_info() ) 
    return str()+" (git:"+git_branch()+"["+git_revision()+"])";
  else
    return str();
}

