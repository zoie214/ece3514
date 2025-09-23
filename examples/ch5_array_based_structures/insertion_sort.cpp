# include <iostream>

template <typename T>
void insertion_sort(T data[], int n) {
    // begin with second character
    for (int k{1}; k < n; k++) {
        T cur{data[k]};  //to relocate cur=data[k]
        int j{k};
        while (j>0 && cur < data[j-1]) {
            data[j] = data[j-1]; // shift right
            j--;
        }
        data[j] = cur; //proper place for cur
    }
}

template <typename T>
void insertion_sort_move_semantics(T data[], int n) {
    for (int k{1}; k < n; k++) {
        
        T cur{std::move(data[k])};

        int j{k};
        while (j>0 && cur < data[j-1]) {

            data[j] = std::move(data[j-1]);
            j--;
        }

        data[j] = std::move(cur);
    }
}

int main1() {
    int arr[]{5, 2, 7, 1, 5, 6, 3, 4, 5, -1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort<int>(arr, size);

    std::cout << "Sorted integers: ";
    for (int i{0}; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

int main2() {
    std::string arr[] = {"banana", "apple", "cherry", "date"};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort<std::string>(arr, size);

    std::cout << "Sorted strings: ";
    for (int i{0}; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}


int main3() {
    int arr[]{5, 2, 7, 1, 5, 6, 3, 4, 5, -1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort_move_semantics<int>(arr, size);

    std::cout << "Sorted integers: ";
    for (int i{0}; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

int main() {
    std::string arr[] = {"banana", "apple", "cherry", "date"};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort_move_semantics<std::string>(arr, size);

    std::cout << "Sorted strings: ";
    for (int i{0}; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}