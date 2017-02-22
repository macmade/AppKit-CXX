/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @brief       ...
 */

#ifndef APPKIT_NS_WINDOW_HPP
#define APPKIT_NS_WINDOW_HPP

#include <OBJCXX.hpp>
#include <AppKit/AppKit.hpp>
#include <AppKit/NSView.hpp>

namespace NS
{
    class Window: public Object
    {
        public:
            
            OBJCXX_USING_BASE( Window, Object );
            
            enum StyleMask: unsigned int
            {
                Borderless              = 0,
                Titled                  = 1 << 0,
                Closable                = 1 << 1,
                Miniaturizable          = 1 << 2,
                Resizable               = 1 << 3,
                TexturedBackground      = 1 << 8,
                UnifiedTitleAndToolbar  = 1 << 12,
                FullScreen              = 1 << 14,
                FullSizeContentView     = 1 << 15,
                UtilityWindow			= 1 << 4,
                DocModalWindow          = 1 << 6,
                NonactivatingPanel		= 1 << 7,
                MaskHUDWindow           = 1 << 13
            };
            
            Window( const Rect & contentRect, unsigned int styleMask, BackingStoreType bufferingType, bool defer );
            
            String title( void ) const;
            void   setTitle( const String & value );
            
            View contentView( void ) const;
            void setContentView( const View & value );
            
            void center( void ) const;
            void makeKeyAndOrderFront( const Object & sender );
    };
}

#endif /* APPKIT_NS_WINDOW_HPP */
