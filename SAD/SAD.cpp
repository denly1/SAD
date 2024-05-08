#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 

class Plant {
private:
    int health; 
public:
    Plant() {
        health = 100; 
    }

    void photosynthesis() {
        std::cout << "Симулируется процесс фотосинтеза...\n";
        
        health += 10; 
    }

    void water() {
        std::cout << "Поливаем растение...\n";
        if (health < 100)
            health += 20;
    }

    void decreaseHealth() {
        if (health > 0)
            health -= 5;
    }

    int getHealth() {
        return health;
    }
};

class Insect {
public:
    void move() {
        std::cout << "Симулируется перемещение насекомых по саду...\n";
    }
};

class Garden {
private:
    std::vector<Plant> plants;
    std::vector<Insect> insects;
public:
    void water_plants() {
        clear_screen();
        std::cout << "Поливаем растения в саду...\n";
        for (auto& plant : plants) {
            plant.water();
        }
        wait_for_input();
    }

    void control_pests() {
        clear_screen();
        std::cout << "Симулируется контроль вредителей в саду...\n";
        wait_for_input();
    }

    void simulate_interaction() {
        clear_screen();
        std::cout << "Симулируется взаимодействие между насекомыми и растениями в саду...\n";
  
        wait_for_input();
    }

    void print_state() {
        clear_screen();
        std::cout << "Текущее состояние сада:\n";
        std::cout << "Количество видов растений: " << plants.size() << std::endl;
        std::cout << "Количество насекомых: " << insects.size() << std::endl;
        wait_for_input();
    }

    void check_health() {
        clear_screen();
        std::cout << "Проверяем состояние здоровья растений в саду...\n";
        for (auto& plant : plants) {
            std::cout << "Здоровье растения: " << plant.getHealth() << std::endl;
            plant.decreaseHealth(); 
        }
        wait_for_input();
    }

    void addPlant(Plant plant) {
        plants.push_back(plant);
    }

    void addInsect(Insect insect) {
        insects.push_back(insect);
    }

    void perform_photosynthesis() {
        clear_screen();
        std::cout << "Производим фотосинтез растений...\n";
        for (auto& plant : plants) {
            plant.photosynthesis();
        }
        wait_for_input();
    }

    void water_unknown_liquid() {
        clear_screen();
        std::cout << "Поливаем растения неизвестной жидкостью...\n";
        for (auto& plant : plants) {
            if (rand() % 2 == 0) { 
                std::cout << "Растение выжило после полива неизвестной жидкостью!\n";
            }
            else {
                std::cout << "Растение умерло после полива неизвестной жидкостью!\n";
                play_death_sound();
            }
        }
        wait_for_input();
    }

private:
    void clear_screen() {
#ifdef _WIN32
        system("cls");
#else
        
       
#endif
    }

    void wait_for_input() {
        std::cout << "Нажмите Enter, чтобы продолжить...";
        std::cin.ignore(); 
        std::cin.get();   
    }

    void play_death_sound() {
        system("start C:\\Users\\Sasha\\Downloads\\plaki-plaki.mp3");
    }


};

void show_menu() {
    std::cout << "Меню управления садом:\n";
    std::cout << "1. Полить растения\n";
    std::cout << "2. Проверить состояние растений\n";
    std::cout << "3. Произвести фотосинтез растений\n";
    std::cout << "4. Провести контроль вредителей\n";
    std::cout << "5. Симулировать взаимодействие\n";
    std::cout << "6. Вывести текущее состояние сада\n";
    std::cout << "7. Проверить здоровье растений и насекомых\n";
    std::cout << "8. Полить растение неизвестной жидкостью\n";
    std::cout << "9. Выйти из программы\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Garden myGarden;

    Plant plant1;
    Plant plant2;

    Insect insect1;
    Insect insect2;
    Insect insect3;

    myGarden.addPlant(plant1);
    myGarden.addPlant(plant2);

    myGarden.addInsect(insect1);
    myGarden.addInsect(insect2);
    myGarden.addInsect(insect3);

    int choice;

    do {
        show_menu();
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            myGarden.water_plants(); 
            break;
        case 2:
            myGarden.check_health(); 
            break;
        case 3:
            myGarden.perform_photosynthesis(); 
            break;
        case 4:
            myGarden.control_pests(); 
            break;
        case 5:
            myGarden.simulate_interaction(); 
            break;
        case 6:
            myGarden.print_state(); 
            break;
        case 7:
            myGarden.check_health(); 
            break;
        case 8:
            myGarden.water_unknown_liquid(); 
            break;
        case 9:
            std::cout << "Выход из программы...\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 9);

    return 0;
}