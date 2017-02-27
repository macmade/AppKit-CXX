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

#include "MainWindowController.hpp"
#include <mutex>

namespace Demo
{
    void MainWindowController::registerClass( void )
    {
        static std::once_flag once;
        
        std::call_once
        (
            once,
            []
            {
                OBJCXX::ClassBuilder cls( "MainWindowController", "NSWindowController" );
                
                cls.instanceMethod< MainWindowController, id                       >( "init",           &MainWindowController::init,          "@16@0:8" ).add();
                cls.instanceMethod< MainWindowController, void, const NS::Object & >( "buttonClicked:", &MainWindowController::buttonClicked, "v24@0:8@16" ).add< void, id >();
                cls.registerClass();
            }
        );
    }
    
    MainWindowController::MainWindowController( void ):
        NS::WindowController
        (
            "MainWindowController",
            [ = ]
            {
                return this->message< id >( "init" ).send();
            }
        )
    {}
    
    id MainWindowController::init( void )
    {
        NS::Button btn( { { 20, 20 }, { 200, 32 } } );
        
        NS::Log( "%@", static_cast< id >( *( this ) ) );
        
        this->setWindow
        (
            NS::Window
            (
                { { 0, 0 }, { 240, 72 } },
                (
                    NS::Window::StyleMask::Titled
                  | NS::Window::StyleMask::Closable
                  | NS::Window::StyleMask::Miniaturizable
                ),
                NS::BackingStoreType::Buffered,
                false
            )
        );
        
        btn.setButtonType( NS::Button::Type::MomentaryPushIn );
        btn.setBezelStyle( NS::Button::BezelStyle::Rounded );
        btn.setTitle( "Click me..." );
        btn.setKeyEquivalent( "\r" );
        btn.setTarget( *( this ) );
        btn.setAction( OBJCXX::RT::GetSelector( "buttonClicked:" ) );
        
        this->window().setTitle( "AppKit++ Demo" );
        this->window().contentView().addSubview( btn );
        
        return *( this );
    }
    
    void MainWindowController::buttonClicked( const NS::Object & sender )
    {
        NS::Alert alert;
        
        NS::Log( "%@", static_cast< id >( sender ) );
        
        alert.setMessageText( "AppKit++" );
        alert.setInformativeText( "hello, world" );
        alert.runModal();
    }
}
