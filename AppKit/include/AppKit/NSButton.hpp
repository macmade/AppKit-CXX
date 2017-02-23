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

#ifndef APPKIT_NS_BUTTON_HPP
#define APPKIT_NS_BUTTON_HPP

#include <OBJCXX.hpp>
#include <AppKit/NSControl.hpp>

namespace NS
{
    class Button: public Control
    {
        public:
            
            OBJCXX_USING_BASE( Button, Control )
            
            enum Type: int
            {
                MomentaryLight          = 0,
                PushOnPushOff           = 1,
                Toggle                  = 2,
                Switch                  = 3,
                Radio                   = 4,
                MomentaryChange         = 5,
                OnOff                   = 6,
                MomentaryPushIn         = 7,
                Accelerator             = 8,
                MultiLevelAccelerator   = 9
            };

            enum BezelStyle: int
            {
                Rounded             = 1,
                RegularSquare       = 2,
                Disclosure          = 5,
                ShadowlessSquare    = 6,
                Circular            = 7,
                TexturedSquare      = 8,
                HelpButton          = 9,
                SmallSquare         = 10,
                TexturedRounded     = 11,
                RoundRect           = 12,
                Recessed            = 13,
                RoundedDisclosure   = 14,
                Inline              = 15,
            };
            
            Button( const Rect & frame );
            
            Type buttonType( void ) const;
            void setButtonType( Type value );
            
            BezelStyle bezelStyle( void ) const;
            void       setBezelStyle( BezelStyle value );
            
            String title( void ) const;
            void   setTitle( const String & value );
            
            String keyEquivalent( void ) const;
            void   setKeyEquivalent( const String & value );
    };
}

#endif /* APPKIT_NS_BUTTON_HPP */
