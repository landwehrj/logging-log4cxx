Macros Influencing Log4cxx {#macros-influencing-log4cxx}
===
<!--
 Note: License header cannot be first, as doxygen does not generate
 cleanly if it before the '==='
-->
<!--
 Licensed to the Apache Software Foundation (ASF) under one or more
 contributor license agreements.  See the NOTICE file distributed with
 this work for additional information regarding copyright ownership.
 The ASF licenses this file to You under the Apache License, Version 2.0
 (the "License"); you may not use this file except in compliance with
 the License.  You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
-->

# Macros that influence Log4cxx

The following macros can be defined in client code to influence how log messages
are set or not.

These macros may be set on a per-file basis(in which case they must be before any
Log4cxx includes), or they may be set globally via your build system.

| Macro | Usage |
| ----- | ----- |
| LOG4CXX\_THRESHOLD | Used to determine if log messages are compiled in or not.  A higher value causes more messages to be compiled out.  See [removing log statements](usage.html#removing-log-statements) for more information. |
| LOG4CXX\_DISABLE\_LOCATION\_INFO | Define this macro to disable location information on log statements.  Location information includes the filename, class name, method name, and line number |
| LOG4CXX\_ENABLE\_STACKTRACE | Define this macro to cause a stacktrace string to be inserted into the MDC with a key of 'stacktrace'.  This requires Boost Stacktrace or C++23 stacktrace to be available when compiling your application.  When using the PatternLayout, print out the stacktrace using the `%%X{stacktrace}` specifier.  See [stacktrace support](stacktrace-support.html) for more information. |
