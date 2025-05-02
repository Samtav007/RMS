#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Property {
    int id;
    string address;
    float price;
    bool available;

public:
    Property(int i, string a, float p) : id(i), address(a), price(p), available(true) {}

    int getId() const { return id; }
    void set(string a, float p) { address = a; price = p; }
    void setAvailable(bool a) { available = a; }
    bool isAvailable() const { return available; }

    void display() const {
        cout << "ID: " << id << ", Address: " << address << ", Price: $" << price << ", Available: " << (available ? "Yes" : "No") << endl;
    }
};

class RealEstateSystem {
    vector<Property> props;
    int counter = 1;

public:
    void add() {
        string a; float p;
        cin.ignore();
        cout << "Address: "; getline(cin, a);
        cout << "Price: "; cin >> p;
        props.emplace_back(counter++, a, p);
    }

    void list() const {
        for (const auto& p : props) p.display();
    }

    void edit() {
        int id; string a; float p;
        cout << "Edit ID: "; cin >> id;
        for (auto& prop : props) {
            if (prop.getId() == id) {
                cin.ignore();
                cout << "New Address: "; getline(cin, a);
                cout << "New Price: "; cin >> p;
                prop.set(a, p);
                return;
            }
        }
        cout << "Not found.\n";
    }

    void remove() {
        int id;
        cout << "Delete ID: "; cin >> id;
        for (auto it = props.begin(); it != props.end(); ++it) {
            if (it->getId() == id) {
                props.erase(it);
                return;
            }
        }
        cout << "Not found.\n";
    }
};

int main() {
    RealEstateSystem sys;
    int ch;
    do {
        cout << "\n1. Add\n2. List\n3. Edit\n4. Delete\n0. Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: sys.add(); break;
            case 2: sys.list(); break;
            case 3: sys.edit(); break;
            case 4: sys.remove(); break;
        }
    } while (ch != 0);
    return 0;
}
