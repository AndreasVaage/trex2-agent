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
#include <trex/europa/Assembly.hh>

#include "EarliestFirstFlawManager.hh"
#include "Trigonometry.hh"
#include "Numeric.hh"
#include "DoNotMatchFilter.hh"


namespace {
  
  /** @brief TREX extra europa extensions
   *
   * A bunch of extensions provided that, while not specific to TREX, comes handy 
   * to design models.
   * The additions are :
   * @li the @c doNotMatch flaw filter that excludes all the flaws relasting to an 
   *     entity that does not match a set of possible names
   * @li the @c EarliestFirst flaw manager that resolve open conditions by picking 
   *     first the on which start the earliest
   * @li the @c cosEq constraint that compute the cosine of an angle in degree
   * @li the @c sinEq constraint that compute the sine of an angle in degree
   * @li the @c absEq constraint that ensures that that its second argument 
   *     is the absolute value of its first
   * @li the @c sqrtEq constraint that censures that its second argument is the 
   *     square root of its first
   * 
   * @author Frederic Py <fpy@mbari.org>
   * @note While these extensions are for now included by deault in the europa 
   *      plugin, we may decide in the futrue to provide them as an extr plugin 
   *      are none of them are critical.  
   */
  class Extensions :public TREX::europa::EuropaPlugin {
    public:
      void registerComponents(TREX::europa::Assembly const &assembly) {
        TREX_REGISTER_FLAW_FILTER(assembly, TREX::europa::DoNotMatchFilter, doNotMatch);
        
	TREX_REGISTER_FLAW_MANAGER(assembly, TREX::europa::EarliestFirstFlawManager,
			EarliestFirst);
        TREX_REGISTER_CONSTRAINT(assembly, TREX::europa::CosineConstraint, cosEq, trex);
        TREX_REGISTER_CONSTRAINT(assembly, TREX::europa::SineConstraint,   sinEq, trex);
        TREX_REGISTER_CONSTRAINT(assembly, TREX::europa::AbsValConstraint, absEq, trex);
        TREX_REGISTER_CONSTRAINT(assembly, TREX::europa::SqrtConstraint,  sqrtEq, trex);
      }
      
    }; // ::Extensions

  Extensions s_extra;
}