// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// ASK A-5
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Dictionary;

class DictEntry {
    public:
        DictEntry(std::string name, std::string description) :
            m_name(name), m_description(description) {}

        std::string name() const { return m_name; }
        std::string description() const { return m_description; }

        bool operator<(const DictEntry& other) {
            return m_name < other.m_name;
        }

    private:
        std::string m_name, m_description;
};

class Dictionary {
    public:
        void add_entry(std::string name, std::string description) {
            m_entries.push_back(DictEntry(name, description));
        }

        void remove_entry(std::string name) {
            for(std::vector<DictEntry>::iterator it = m_entries.begin(); it < m_entries.end(); it++) {
                if (it->name() == name) {
                    m_entries.erase(it);
                    return;
                }
            }
        }

        DictEntry get_entry(std::string name) {
            for(std::vector<DictEntry>::iterator it = m_entries.begin(); it < m_entries.end(); it++) {
                if (it->name() == name) {
                    return *it;
                }
            }
            throw std::runtime_error("Did't find element");
        }

        void write_to_file(std::string file_name) {
            std::ofstream out(file_name.c_str());
            for(DictEntry& entry : m_entries) {
                out << entry.name() << "$" << entry.description() << '\n';
            }
        }

        void load_from_file(std::string file) {
            std::ifstream in(file.c_str());

            std::string line;
            while (std::getline(in, line)) {
                int pos = line.find('$');
                std::string name = line.substr(0, pos);
                std::string desc = line.substr(pos + 1);
                add_entry(name, desc);
            }
        }

        std::vector<DictEntry> sorted() const {
            std::vector<DictEntry> retval(m_entries);
            std::sort(retval.begin(), retval.end());
            return retval;
        }

    private:
        std::vector<DictEntry> m_entries;
};

int main(int argc, char** argv) {
    Dictionary dict;

    dict.add_entry("One", "One is a cool number");
    dict.add_entry("Two", "Two is a cool number");
    dict.add_entry("Kek", "Two is a cool number");
    dict.add_entry("Pepegas", "Two is a cool number");
    dict.add_entry("monkaS", "Two is a cool number");

    std::cout << dict.get_entry("One").description() << std::endl;
    std::cout << dict.get_entry("Two").description() << std::endl;

    try {
        std::cout << dict.get_entry("None").name() << std::endl;
    } catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nSorted: \n";
    for (DictEntry& entry: dict.sorted()) {
        std::cout << entry.name() << std::endl;
    }

    dict.write_to_file("out_5.txt");

    dict.load_from_file("out_5.txt");
    std::cout << "\nSorted: \n";
    for (DictEntry& entry: dict.sorted()) {
        std::cout << entry.name() << " : " << entry.description() << std::endl;
    }
    return 42;
}
