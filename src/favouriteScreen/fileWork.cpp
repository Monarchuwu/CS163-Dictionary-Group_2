#include"fileWork.h"
namespace minh
{

    std::string defOfWord(std::string word, const std::string& fileName)
    {
        std::ifstream fin;
        fin.open(fileName);
        if (!fin.is_open())
        {
            std::cout << "Can not open file";
            fin.close();
            return "";
        }
        std::string def;
        bool find = 0;
        while (std::getline(fin, def)) {
            //std::cout << def << std::endl;
            int k = int(word.size());
            for (int i = 0; i <= word.size() - 1; i++)
            {
                if (def[i] != word[i]) break;
                if (i == word.size() - 1 && def[i + 1] == 9)
                {
                    find = 1;
                    def  = def.substr(k + 1);

                    break;
                }
            }
            if(find) break;
        }
        if (find) {
           // std::cout << "Find definition successfully" << std::endl;
            return def;
        }
            std::cout << "Can not find word in " << fileName <<std::endl;
            fin.close();
            return "";
    }
    // void addToEndOfFile(int id, const std::string& filename, std::vector<Words::Word> v) {
    //        std::ofstream fout(filename, std::ios::app);
    //        if (!fout.is_open()) {
    //        std::cout << "Can not open file" << std::endl;
    //        fout.close();
    //        return;
    //        }
    //        if (defOfWord(v[id].word, filename) == "")
    //        for (int i = 0; i < v[id].definitions.size(); i++)
    //            fout << v[id].word << "\t" << v[id].definitions[i] << std::endl;
    //        else std::cout << "Word have already been added to favourite list" << std::endl;
    //        fout.close();
    //        return;
    //}

        std::string takeLine(int n, const std::string &filename) 
       {
            
            std::ifstream fin;
            fin.open(filename);
            if (!fin.is_open()) {
                std::cout << "Can not open file " << filename << std::endl;
                fin.close();
                return "";
            }
            std::string str;
            
            for (int i = 0; i < n;i++)
            {
                if (fin.eof()) 
                {
                str = "";
                break;
                }
                std::getline(fin, str);
            }
            fin.close();
            //std::cout << str << std::endl;
            return str;   
        }

      

        void clearFromFile(const std::string word, const std::string& filename)
        {
            std::queue<std::string> lines;

            std::ifstream fin;
            fin.open(filename);
            if (!fin.is_open()) {
                std::cout << "Can not open file";
                fin.close();
                return;
            }
            std::string str;
          
            while (std::getline(fin, str)) {
                // std::cout << def << std::endl;
                bool find = 0;
                int k = int(word.size());
                for (int i = 0; i <= word.size() - 1; i++) 
                {
                    if (str[i] != word[i]) break;
                    if (i == word.size() - 1 && str[i + 1] == 9)
                    {
                        find = 1;
                        break;
                    }
                }
                if (!find) lines.push(str);
            }
 

            std::ofstream fout(filename, std::ios::trunc);
           
            if (!fout.is_open()) 
            {
                std::cout << "Can not open file";
                fin.close();
                fout.close();
                return;
            }
            while (lines.size())
            {
                fout << lines.front() <<std:: endl;
                lines.pop();
            }
            fin.close();
            return;
        }
}