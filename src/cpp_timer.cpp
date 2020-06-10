/*
 * Copyright 2020 <copyright holder> <email>
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

#include "cpp_timer.h"

cpp_Timer::cpp_Timer()
{
    _start = std::chrono::high_resolution_clock::now();
}

cpp_Timer::~cpp_Timer()
{
    _end = std::chrono::high_resolution_clock::now();
    _duration = std::chrono::duration_cast<std::chrono::duration<double>>(_end - _start);
    double ms = _duration.count() * 1000.0;
    std::cout << "Final duration : " << _duration.count() << "s (" << ms << "ms)" << std::endl;
}
