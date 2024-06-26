// add.h
//
// Copyright (C) 2003, 2004 Jason Bevins
//
// This library is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 2.1 of the License, or (at
// your option) any later version.
//
// This library is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
// License (COPYING.txt) for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// The developer's email is jlbezigvins@gmzigail.com (for great email, take
// off every 'zig'.)
//

#ifndef NOISE_MODULE_ADD_H
#define NOISE_MODULE_ADD_H

#include "modulebase.h"

namespace noise
{

  namespace module
  {

    /// @addtogroup libnoise
    /// @{
    
    /// @addtogroup modules
    /// @{
    
    /// @defgroup combinermodules Combiner Modules
    /// @addtogroup combinermodules
    /// @{
    
    /// Noise module that outputs the sum of the two output values from two
    /// source modules.
    ///
    /// @image html moduleadd.png
    ///
    /// This noise module requires two source modules.
    class NOISE_SHARED_EXPORT Add: public Module
    {

      public:

        /// Constructor.
        Add ();

        virtual int GetSourceModuleCount () const
        {
          return 2;
        }

        virtual double GetValue (double x, double y, double z) const;

    };

    /// @}

    /// @}

    /// @}

  }

}

#endif
