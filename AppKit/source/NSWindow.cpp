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

#include <AppKit.hpp>

namespace NS
{
    Window::Window( const Rect & contentRect, unsigned int styleMask, BackingStoreType bufferingType, bool defer ):
        Object
        (
            "NSWindow",
            [ = ]
            {
                return this->message< id >( "initWithContentRect:styleMask:backing:defer:" ).send< NS::Rect, unsigned int, BackingStoreType, bool >( contentRect, styleMask, bufferingType, defer );
            }
        )
    {}
    
    String Window::title( void ) const
    {
        return this->message< id >( "title" ).send();
    }
    
    void Window::setTitle( const String & value )
    {
        this->message< void >( "setTitle:" ).send< id >( value );
    }
    
    View Window::contentView( void ) const
    {
        return this->message< id >( "contentView" ).send();
    }
    
    void Window::setContentView( const View & value )
    {
        this->message< void >( "setContentView:" ).send< id >( value );
    }
    
    void Window::center( void ) const
    {
        this->message< void >( "center" ).send();
    }
    
    void Window::makeKeyAndOrderFront( const Object & sender )
    {
        this->message< void >( "makeKeyAndOrderFront:" ).send< id >( sender );
    }
}
