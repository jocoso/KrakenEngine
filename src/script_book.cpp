#include "../include/script_book.h"

namespace rawr {
    string script_book::get_current_dir() {
        char tmp[256];
        getcwd(tmp, 256);
        return tmp;
    }

    void script_book::execute_script( ifstream &file ) {
        std::vector<char> buffer(( 
                    std::istreambuf_iterator<char>( file )),
                    std::istreambuf_iterator<char>());
        buffer.push_back('\0');
        this->doc.parse<0>( &buffer[0] );

        root_node = this->doc.first_node("main");

        // Iterate over the student nodes
        for(rapidxml::xml_node<> *chapter_node = root_node->first_node( "chapter" );
        chapter_node; chapter_node = chapter_node->next_sibling()) {
            
            cout << "Title = " << chapter_node->first_attribute( "title" )->value();
            cout << endl;

            for(rapidxml::xml_node<> *prompt_node = chapter_node->first_node( "prompt" );
            prompt_node; prompt_node = prompt_node->next_sibling()) {
                cout << prompt_node->value() << endl;
            }

        }
    }
}