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
    Button::Button( const Rect & frame ):
        Control
        (
            "NSButton",
            [ = ]
            {
                return this->message< id >( "initWithFrame:" ).send< Rect >( frame );
            }
        )
    {}
    
    Button::Type Button::buttonType( void ) const
    {
        return this->message< Type >( "buttonType" ).send();
    }
    
    void Button::setButtonType( Type value )
    {
        this->message< void >( "setButtonType:" ).send< Type >( value );
    }
    
    Button::BezelStyle Button::bezelStyle( void ) const
    {
        return this->message< BezelStyle >( "bezelStyle" ).send();
    }
    
    void Button::setBezelStyle( BezelStyle value )
    {
        this->message< void >( "setBezelStyle:" ).send< BezelStyle >( value );
    }
    
    String Button::title( void ) const
    {
        return this->message< id >( "title" ).send();
    }
    
    void Button::setTitle( const String & value )
    {
        this->message< void >( "setTitle:" ).send< id >( value );
    }
    
    String Button::keyEquivalent( void ) const
    {
        return this->message< id >( "keyEquivalent" ).send();
    }
    
    void Button::setKeyEquivalent( const String & value )
    {
        this->message< void >( "setKeyEquivalent:" ).send< id >( value );
    }
}
