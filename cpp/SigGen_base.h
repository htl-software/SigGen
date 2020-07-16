/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK SigGen.
 *
 * REDHAWK SigGen is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK SigGen is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
#ifndef SIGGEN_BASE_IMPL_BASE_H
#define SIGGEN_BASE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Component.h>
#include <ossie/ThreadedComponent.h>

#include <bulkio/bulkio.h>

namespace enums {
    // Enumerated values for shape
    namespace shape {
        static const std::string sine = "sine";
        static const std::string square = "square";
        static const std::string triangle = "triangle";
        static const std::string sawtooth = "sawtooth";
        static const std::string pulse = "pulse";
        static const std::string constant = "constant";
        static const std::string whitenoise = "whitenoise";
        static const std::string lrs = "lrs";
    }
    // Enumerated values for use_complex
    namespace use_complex {
        static const CORBA::Long REAL_ONLY = 1;
        static const CORBA::Long COMPLEX = 2;
    }
}

class SigGen_base : public Component, protected ThreadedComponent
{
    public:
        SigGen_base(const char *uuid, const char *label);
        ~SigGen_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:
        // Member variables exposed as properties
        /// Property: frequency
        double frequency;
        /// Property: sample_rate
        double sample_rate;
        /// Property: magnitude
        double magnitude;
        /// Property: shape
        std::string shape;
        /// Property: xfer_len
        CORBA::Long xfer_len;
        /// Property: throttle
        bool throttle;
        /// Property: stream_id
        std::string stream_id;
        /// Property: chan_rf
        double chan_rf;
        /// Property: col_rf
        double col_rf;
        /// Property: sri_blocking
        bool sri_blocking;
        /// Property: use_complex
        CORBA::Long use_complex;

        // Ports
        /// Port: dataFloat_out
        bulkio::OutFloatPort *dataFloat_out;
        /// Port: dataShort_out
        bulkio::OutShortPort *dataShort_out;

    private:
};
#endif // SIGGEN_BASE_IMPL_BASE_H
