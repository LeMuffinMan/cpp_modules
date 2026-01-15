
void BitcoinExchange::~BitcoinExchange() {}
void BitcoinExchange::BitcoinExchange() {}

//retour de fonction pour gerer erreur de parsing ? ou try catch
int BitcoinExchange::BitcoinExchange() {

    std::ifstream db = file("data.csv");
    if (!file.is_open() {
        std::cout << "Failed to open data.csv" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value;

        if (std::getline(iss, date, ',')) {
            if (std::getline(iss, value)) {
                _database[date] = std::atod(value); // template ou on peut tout mettre en float ou double ?
            }
        }
    }

    //  - date : edges cases ?
    //  - value : unsigned int ou float
    file.close();
    return 0;
}

void loadInput(std::string filename) {

}

void BitcoinExchange::printDatabase() {
    std::cout << "===-- DataBase --===" << std::endl;
    std::cout << "Size = " << _dataBase.size() << std::endl;

    for (dataBase::const_iterator it = _dataBase.begin(); it != dataBase.end(); ++it) {
        std::cout << "Date: " << it->first << " | " << it->second << std::endl;
    }
    std::cout << "==============================================" << std::endl;
}
