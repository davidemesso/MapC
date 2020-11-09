# MapC
A simple Map structure (also called Dictionary) in C, also supporting nested maps.

It uses string key and void* value to implement generic type content for the value.7

NOTE: m_GetValuePointer return a Node**, used for some applications as removing elements or working on it, instead m_GetValue returns a simple Node* to be used as simple value

[main.c](main.c) is a file used to test every funcionality and to present some examples
