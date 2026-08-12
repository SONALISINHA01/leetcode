class Solution {
public:
    int index = 0;
    unordered_map<string, int> parse_formula(string& formula) {
        unordered_map<string, int> curr_map;
        string curr_atom = "", curr_count = "";
        while(index < formula.size()) {
            if (isupper(formula[index])) {
                if (!curr_atom.empty()) {
                    if (curr_count.empty()) {
                        curr_map[curr_atom]++;
                    } else {
                        curr_map[curr_atom] += stoi(curr_count);
                    }
                }
                curr_atom = formula[index];
                curr_count = "";
                index++;
            } else if (islower(formula[index])) {
                curr_atom += formula[index];
                index++;
            } else if (isdigit(formula[index])) {
                curr_count += formula[index];
                index++;
            } else if (formula[index] == '(') {
                index++;
                unordered_map<string, int> nested = parse_formula(formula);
                for (auto& [atom, count] : nested) {
                    curr_map[atom] += count;
                }
            } else if (formula[index] == ')') {
                if (!curr_atom.empty()) {
                    if (curr_count.empty()) {
                        curr_map[curr_atom]++;
                    } else {
                        curr_map[curr_atom] += stoi(curr_count);
                    }
                }
                index++;
                string multiplier;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : curr_map) {
                        curr_map[atom] = count * mult;
                    }
                }
                return curr_map;
            }
        }
        if (!curr_atom.empty()) {
            if (curr_count.empty()) {
                curr_map[curr_atom] += 1;
            } else {
                curr_map[curr_atom] += stoi(curr_count);
            }
        }
        return curr_map;
    }
    string countOfAtoms(string formula) {
        unordered_map<string,int> finalmap = parse_formula(formula);
        map<string,int> sorted_map(finalmap.begin(),finalmap.end());
        string ans;
        for(auto &[atom,count]:sorted_map){
            ans+=atom;
            if(count>1){
                ans+=to_string(count);
            }
        }
        return ans;
    }
};