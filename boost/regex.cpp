// begin-snippet importregex
#include <boost/regex.hpp>
using namespace boost
// end-snippet

// begin-snippet match
// parameter text
// parameter group
// parameter pattern
smatch group;
if (regex_match(text, group, pattern)) {
    group.str();
    group.str(1);
}
// end-snippet

// begin-snippet search
// parameter text
// parameter group
// parameter pattern
smatch group;
if (regex_search(text, group, pattern)) {
    group.str();
}
// end-snippet

// begin-snippet replace
// parameter text
// parameter pattern
// parameter format
// parameter result
string result = regex_replace(text, pattern, format);
// end-snippet