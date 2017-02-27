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

#include "ApplicationDelegate.hpp"
#include <mutex>

namespace Demo
{
    void ApplicationDelegate::registerClass( void )
    {
        static std::once_flag once;
        
        std::call_once
        (
            once,
            []
            {
                OBJCXX::ClassBuilder cls( "ApplicationDelegate", "NSObject" );
                
                cls.instanceMethod< ApplicationDelegate, void, const NS::Notification & >( "applicationDidFinishLaunching:", &ApplicationDelegate::applicationDidFinishLaunching, "v24@0:8@16" ).add< void, id >();
                cls.instanceMethod< ApplicationDelegate, void, const NS::Notification & >( "applicationWillTerminate:",      &ApplicationDelegate::applicationWillTerminate,      "v24@0:8@16" ).add< void, id >();
                cls.addProperty( "mainWindowController", OBJCXX::ClassBuilder::TypeObject );
                cls.registerClass();
            }
        );
    }
    
    MainWindowController ApplicationDelegate::mainWindowController( void ) const
    {
        return this->message< id >( "mainWindowController" ).send();
    }
    
    void ApplicationDelegate::mainWindowController( const MainWindowController & o )
    {
        return this->message< void >( "setMainWindowController:" ).send< id >( o );
    }
    
    void ApplicationDelegate::applicationDidFinishLaunching( const NS::Notification & notification )
    {
        NS::Log( "%@", static_cast< id >( notification ) );
        Demo::MainWindowController::registerClass();
        
        this->mainWindowController( {} );
        this->mainWindowController().window().center();
        this->mainWindowController().window().makeKeyAndOrderFront( nullptr );
    }
    
    void ApplicationDelegate::applicationWillTerminate( const NS::Notification & notification )
    {
        NS::Log( "%@", static_cast< id >( notification ) );
    }
}
