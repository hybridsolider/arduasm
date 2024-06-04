#include <iostream>
# include <string>
#define str std::string

struct Settings {
    int number_of_ints = 5;
    int number_of_chars = 5;
    int number_of_bools = 5;
    std::string entry_point = "init";
};

class Arduasm{
private:
    class Functions {
        private:
            
            void find_type(str var){
                switch (var)
                {
                case "&":
                    
                    break;
                
                default:
                    break;
                }
            }
        
        public:
            template <typename T>
            void out(T to_display){
                std::cout << to_display;
            }
            void after_syscall(str rax, str rdi, str rsi, str rdx){
                
                
                switch ()
                {
                case 1:
                    out()
                    break;
                
                default:
                    break;
                }
            }
            
    };  

    int *ints;
    char *chars;
    bool *bools;
    std::string entry_point = "init";




        
public:
    Arduasm(Settings* settings){
        ints = new int[settings->number_of_ints];
        chars = new char[settings->number_of_chars];
        bools = new bool[settings->number_of_bools];
        entry_point = settings->entry_point;
    }

};

int main(){
    Settings settings;
    Arduasm aasm = Arduasm(&settings);
    return 0;
}