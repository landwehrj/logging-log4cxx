/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <log4cxx/logstring.h>
#include <log4cxx/helpers/date.h>

#define LOG4CXX_USEC_PER_SEC 1000000LL
#ifndef INT64_C
	#define INT64_C(x) x ## LL
#endif

using namespace log4cxx;
using namespace log4cxx::helpers;

IMPLEMENT_LOG4CXX_OBJECT(Date)


Date::GetCurrentTimeFn Date::getCurrentTimeFn = Date::getCurrentTimeStd;

Date::Date() : time(getCurrentTimeFn())
{
}

Date::Date(log4cxx_time_t t) : time(t)
{
}

Date::~Date()
{
}

log4cxx_time_t Date::getMicrosecondsPerDay()
{
	return 86400000000ull;
}

log4cxx_time_t Date::getMicrosecondsPerSecond()
{
	return LOG4CXX_USEC_PER_SEC;
}


log4cxx_time_t Date::getNextSecond() const
{
	return ((time / LOG4CXX_USEC_PER_SEC) + 1) * LOG4CXX_USEC_PER_SEC;
}

void Date::setGetCurrentTimeFunction(GetCurrentTimeFn fn){
	getCurrentTimeFn = fn;
}

log4cxx_time_t Date::currentTime(){
	return getCurrentTimeFn();
}

log4cxx_time_t Date::getCurrentTimeStd(){
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
