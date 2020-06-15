/*
 * Copyright 2020 <Olivier Mullierr> <oliviermullier@gmail.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
/**
 * class to time any scope an object of this class is created in.
 * behaviour: create an object of this class in any scope you want to time.
 * The duration between its creation and destruction is sent to cout.
 */
class cpp_Timer
{
    
private:
    bool _print_on_destruct;
    std::chrono::high_resolution_clock::time_point _start, _end;
    std::chrono::duration<double> _duration;
public:
    /**
     * Default constructor: stores the starting time the object is created
     */
    cpp_Timer(bool print_on_destruct = false);

    void restart();
    
    double get_duration();
    /**
     * Destructor : print in the standard output the time between the creation of the object and the destruction of it.
     */
    ~cpp_Timer();

};
#endif // TIMER_H
