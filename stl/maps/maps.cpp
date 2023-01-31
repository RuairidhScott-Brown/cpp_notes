/*
MAPS
Maps are associative containers that store elements formed by
a combination of a key value and a mapped value, following a specific order.

COMMON MAP MEMBER FUNCTIONS

The template
    std::map <key_type, data_type>

The Declaration
    std::map<string, int> m;

Size of the map
    int length = m.size();

Inserting
    m.insert(std::make_pair("hello", 9))

Erasing an Element
    m.erase(key)

Finding an element
    map<string,int>::iterator itr=m.find(val);
    Gives the iterator to the element val if it is found otherwise returns m.end().

Access the values
    m[key]
*/

int main() {

    return 0;
}