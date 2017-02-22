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
    Control::Control( const Rect & frame ):
        View
        (
            "NSControl",
            [ = ]
            {
                return this->message< id >( "initWithFrame:" ).send< Rect >( frame );
            }
        )
    {}
    
    bool Control::enabled( void ) const
    {
        return this->message< bool >( "enabled" ).send();
    }
    
    void Control::setEnabled( bool value )
    {
        this->message< void >( "setEnabled:" ).send< bool >( value );
    }
    
    Object Control::target( void ) const
    {
        return this->message< id >( "target" ).send();
    }
    
    void Control::setTarget( const Object & value )
    {
        this->message< void >( "setTarget:" ).send< id >( value );
    }
    
    SEL Control::action( void ) const
    {
        return this->message< SEL >( "action" ).send();
    }
    
    void Control::setAction( SEL value )
    {
        this->message< void >( "setAction:" ).send< SEL >( value );
    }
}
