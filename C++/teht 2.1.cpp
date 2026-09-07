#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> find_all_elements(const string &xml, string tag_name);

int main() {
    string filename;
    vector<string> text;
    while (true) {
        cout << "\nEnter filename (.xml only) or stop: ";
        cin >> filename;
        if (filename == "stop") {
            exit(0);
        }
        ifstream inputFile(filename); // try opening file
        if (!inputFile.is_open()) { // if opening file fails start again
            cout << "\nError opening file!";
        } else { // if file opened succesfully then
            string line, xml_content, tag_name;
            while (getline(inputFile, line)) { // read each line and store in xml_content
                xml_content.append(line);
                line.erase();
            }
            while (true) {
                cout << "\nPlease enter tag or stop: ";
                cin >> tag_name;
                if (tag_name == "stop") {
                    exit(0);
                }
                text = find_all_elements(xml_content , tag_name);
                if (text.empty()) {
                    cout << "\nNo elements found!";
                }
                else {
                    for (int i = 0; i < text.size(); i++) {
                        cout << "\n" << tag_name << ": " << text[i];
                    }
                }
            }
        }
    }
}

vector<string> find_all_elements(const string &xml, string tag_name) {
    int start_pos = 0;
    int tag_len = tag_name.length() + 2;
    int text_len = 0;
    string tag;
    vector<string> tags;

    size_t pos = xml.find("<" + tag_name + ">", start_pos); // Find pos of first tag starting at <
    while (pos != string::npos) { // while a tag has been found
        start_pos = pos + tag_len; // start pos is current pos + length of tag eg. first character after >
        pos = xml.find("</" + tag_name + ">", start_pos); // find location of closing tag
        if (pos == string::npos) {
            break;
        }
        text_len = pos - start_pos; // length of text is current position - starting pos
        tag = xml.substr(start_pos, text_len); // save text to tag
        tags.push_back(tag); // push tag to tags
        start_pos = pos + tag_len; // move new starting point forward
        pos = xml.find("<" + tag_name + ">", start_pos); // find new tag and repeat
    }
    return tags;
}
