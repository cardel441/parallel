

// Шаг 1: Разработка классов для технических характеристик устройств
// Для начала создадим классы GpuSpec, CpuSpec, RamSpec и LanSpec, которые будут хранить информацию о соответствующих устройствах.

#include <iostream>
#include <fstream>
#include <string>

class GpuSpec {
public:
    std::string model;
    int memory; // в МБ

    void Print() const {
        std::cout << "GPU Model: " << model << ", Memory: " << memory << " MB" << std::endl;
    }

    void Export(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << "GPU Model: " << model << ", Memory: " << memory << " MB\n";
            file.close();
        }
    }

    void Import(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            getline(file, model, ',');
            file >> memory;
            file.close();
        }
    }
};

class CpuSpec {
public:
    std::string model;
    int cores;

    void Print() const {
        std::cout << "CPU Model: " << model << ", Cores: " << cores << std::endl;
    }

    void Export(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << "CPU Model: " << model << ", Cores: " << cores << "\n";
            file.close();
        }
    }

    void Import(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            getline(file, model, ',');
            file >> cores;
            file.close();
        }
    }
};

class RamSpec {
public:
    int size; // в МБ

    void Print() const {
        std::cout << "RAM Size: " << size << " MB" << std::endl;
    }

    void Export(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << "RAM Size: " << size << " MB\n";
            file.close();
        }
    }

    void Import(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> size;
            file.close();
        }
    }
};

class LanSpec {
public:
    std::string type; // например, Ethernet
    int speed; // в Мбит/с

    void Print() const {
        std::cout << "LAN Type: " << type << ", Speed: " << speed << " Mbps" << std::endl;
    }

    void Export(const std::string& filename) const {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << "LAN Type: " << type << ", Speed: " << speed << " Mbps\n";
            file.close();
        }
    }

    void Import(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            getline(file, type, ',');
            file >> speed;
            file.close();
        }
    }
};


// Шаг 2: Разработка класса ClusterNode
// Теперь создадим класс ClusterNode, который будет содержать сведения об установленных устройствах.

class ClusterNode {
private:
    GpuSpec gpu;
    CpuSpec cpu;
    RamSpec ram;
    LanSpec lan;

public:
    ClusterNode(const GpuSpec& g, const CpuSpec& c, const RamSpec& r, const LanSpec& l)
        : gpu(g), cpu(c), ram(r), lan(l) {}

    void Print() const {
        gpu.Print();
        cpu.Print();
        ram.Print();
        lan.Print();
    }

    void Export(const std::string& filename) const {
        gpu.Export(filename);
        cpu.Export(filename);
        ram.Export(filename);
        lan.Export(filename);
    }

    void Import(const std::string& filename) {
        gpu.Import(filename);
        cpu.Import(filename);
        ram.Import(filename);
        lan.Import(filename);
    }
};


// Шаг 3: Разработка класса Cluster
// Теперь создадим класс Cluster, который будет моделировать структуру вычислительного кластера.

#include <vector>

class Cluster {
private:
    std::vector<ClusterNode> nodes;

public:
    void AddNode(const ClusterNode& node) {
        nodes.push_back(node);
    }

    void Print() const {
        for (const auto& node : nodes) {
            node.Print();
            std::cout << "---------------------" << std::endl;
        }
    }

    void Export(const std::string& filename) const {
        for (const auto& node : nodes) {
            node.Export(filename);
        }
    }

    void Import(const std::string& filename) {
        // Импорт узлов можно реализовать по аналогии с предыдущими классами
        // Для простоты здесь не реализуем
    }
};


