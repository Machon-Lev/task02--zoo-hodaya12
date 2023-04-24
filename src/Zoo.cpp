#include "..\include\Zoo.h"


void Zoo::stop(int i)
{
	_List[i]->stop();
}

void Zoo::move(int i)
{
	_List[i]->move();
}

void Zoo::create(char type, string name)
{
    int row=rand() % ROWS;
    int col = rand() % COLS;
    switch (type) {
    case 'L':
        _List.push_back(std::make_unique<Lion>(name, Location(row, col)));
        break;
    case 'M':
        _List.push_back(std::make_unique<Monkey>(name, Location(row, col)));
        break;
    case 'G':
        _List.push_back(std::make_unique<Goose>(name, Location(row, col)));
        break;
    default:
        cout << "Invalid operation";
        break;
    }
}

void Zoo::del(int i)
{
    _List.erase(_List.begin() + i);
}

void Zoo::delAll(char a)
{
    if(a=='L')
        _List.erase(std::remove_if(_List.begin(), _List.end(), [](const unique_ptr<Animal>& obj) { return typeid(*obj) == typeid(Lion); }), _List.end());
    if (a == 'M')
        _List.erase(std::remove_if(_List.begin(), _List.end(), [](const unique_ptr<Animal>& obj) { return typeid(*obj) == typeid(Monkey); }), _List.end());
    if (a == 'G')
        _List.erase(std::remove_if(_List.begin(), _List.end(), [](const unique_ptr<Animal>& obj) { return typeid(*obj) == typeid(Goose); }), _List.end());
   
}

void Zoo::help()
{
    
    cout << "Enter 'help' for a list of commands." << endl;
    cout << "Enter 'exit' to exit\n";
    cout << "Enter . to step all the animals\n";
    cout << "Enter 'stop' to stop animal\n";
    cout << "Enter 'move' to move animal\n";
    cout << "Enter 'create' to create a new animal\n";
    cout << "Enter 'del' to delete animal\n";
    cout << "Enter 'delAll' to delete all animals from one type\n";
}

void Zoo::step()
{
    for (unique_ptr<Animal>& i : _List) {
        i->step();
    }
}

void Zoo::print_map()
{
    cout << "this is the zoo map:" << endl;
    bool isExist = false;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            isExist = false;
            for (unique_ptr<Animal>& t : _List) {
                if (t->getLocation() == Location(i, j)) {
                    if (!isExist)
                        cout << t->getInitial();
                    isExist = true;
                }
            }
            if (!isExist)
                cout << ".";
        }
        cout << "\n";
    }
}

void Zoo::print_list()
{
    cout << "this is a list of the animals in the zoo:" << endl;
    int i1 = 0;
    for (unique_ptr<Animal>& t : _List) {
        cout << "Animal number: " << i1 << endl;
        i1++;
        t->printDetails();
    }
}

Zoo::Zoo()
{
    create('L', "Simba");
    create('L', "Mufasa");
    create('M', "Rafiki");
    create('G', "Akka");
    create('G', "Morten");
}



void Zoo::run()
{
    int index;
    string command;
    char type;
    string name;
    
    print_map();
    print_list();
    help();
    cin >> command;
    while (command!="exit") {
        if (command == ".") {
            step();
        }
        else if (command == "stop") {
            cout << "enter index of animal to stop\n";
            cin >> index;
            if (index >= _List.size()) {
                cout << "Index out of range!";
            }
            else {
                stop(index);
                step();
            }
        }
        else if (command == "move") {
            cout << "enter index of animal to move\n";
            cin >> index;
            if (index >= _List.size()) {
                cout << "Index out of range!";
            }
            else {
                move(index);
                step();
            }
        }
        else if (command == "create") {
            cout << "enter L for Lion M for Monkey and G for Goose\n";
            cin >> type;
            if (type != 'M' && type != 'L' && type != 'G') {
                cout << "invalid input";
            }
            else {
                cout << "enter the name of the animal\n";
                cin >> name;
                create(type, name);
                step();
            }
        }
        else if (command == "del") {
            cout << "enter index of animal to delete\n";
            cin >> index;
            if (index >= _List.size()) {
                cout << "Index out of range!";
            }
            else {
                del(index);
                step();
            }
        }
        else if (command == "delAll") {
            cout << "enter L for Lion M for Monkey and G for Goose\n";
            cin >> type;
            if (type != 'M' && type != 'L' && type != 'G') {
                cout << "invalid input";
            }
            else {
                delAll(type);
                step();
            }
        }
        else if (command == "help") {
            help();
        }
        else if (command == "exit") {
            // exit program
        }
        else {
            cout << "invalid command";
        }
        
        print_map();
        print_list();
        
        help();
        cin >> command;
    }
}
