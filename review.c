#include <stdio.h>
#include <stdbool.h>

// ============ CAC FUNCTION ============

// Function kiem tra mang rong
// Tra ve 1 neu mang rong, 0 neu khong rong
int kiemTraMangRong(int size) {
    if(size == 0) {
        printf("Mang rong! Vui long nhap mang.\n");
        return 1;
    }
    return 0;
}

// Function 1: Nhap mang
// Tra ve so luong phan tu da nhap
int nhapMang(int arr[]) {
    int size;
    printf("Nhap mang \n");
    printf("Nhap so luong phan tu(1-100):");
    scanf("%d", &size);

    // Kiem tra so hop le
    if(size < 1 || size > 100) {
        printf("So luong khong hop le!");
        return 0;
    }

    // Nhap tung phan tu
    printf("Nhap %d phan tu cua ban:\n", size);
    for(int i = 0; i < size; i++) {
        printf("Phan tu thu %d:", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Da nhap thanh cong %d phan tu \n", size);
    return size;
}

// Function 2: Xuat mang
void xuatMang(int arr[], int size) {
    printf("Xuat mang\n");
    if(kiemTraMangRong(size)) return;

    printf("Mang hien tai: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function 3: In mang giam dan
void inMangGiamDan(int arr[], int size) {
    printf("In mang giam dan\n");
    if(kiemTraMangRong(size)) return;

    // Tim max
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    // Tim min
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Dem tu max xuong min
    printf("Mang giam dan: ");
    for(int num = max; num >= min; num--) {
        for(int i = 0; i < size; i++) {
            if(arr[i] == num) {
                printf("%d ", num);
            }
        }
    }
    printf("\n");
}

// Function 4: Kiem tra tat ca so le
void kiemTraTatCaLe(int arr[], int size) {
    printf("Kiem tra tat ca phan tu la so le\n");
    if(kiemTraMangRong(size)) return;

    int tatCaLe = 1;
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            tatCaLe = 0;
        }
    }

    if(tatCaLe == 1) {
        printf("Tat ca phan tu deu la so le!\n");
    } else {
        printf("Khong phai tat ca phan tu la so le!\n");
    }
}

// Function 5: Tim kiem gia tri
void timKiemGiaTri(int arr[], int size) {
    printf("Tim kiem gia tri\n");
    if(kiemTraMangRong(size)) return;

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int dem = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == x) {
            dem = dem + 1;
        }
    }

    if(dem > 0) {
        printf("Gia tri %d xuat hien %d lan trong mang.\n", x, dem);
    } else {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }
}

// Function 6: Hien thi so nguyen to
void hienThiSoNguyenTo(int arr[], int size) {
    printf("Hien thi cac so nguyen to\n");
    if(kiemTraMangRong(size)) return;

    printf("Cac so nguyen to trong mang: ");
    int coNguyenTo = 0;

    for(int i = 0; i < size; i++) {
        int num = arr[i];


        if(num <= 1) {
            continue;
        }

        // Gia su la so nguyen to
        int laNguyenTo = 1;

        for(int j = 2; j < num; j++) {
            if(num % j == 0) {
                laNguyenTo = 0;
                break;
            }
        }
        if(laNguyenTo == 0) {
            continue;
        }

        // Chi chay den day neu la so nguyen to
        printf("%d ", num);
        coNguyenTo = coNguyenTo + 1;
    }


    if(coNguyenTo == 0) {
        printf("Khong co so nguyen to nao trong mang.\n");
        return;
    }

    printf("\nTong cong co %d so nguyen to.\n", coNguyenTo);
}

// ============ CHUONG TRINH CHINH ============

int main() {
    int choice;
    int size = 0;
    int arr[100];
    int running = 1;
    printf("==== QUAN LY ARRAY ==== ");
    do {
        // Hien thi menu
        printf("\n--- MENU ---\n");
        printf("1 - Nhap mang\n");
        printf("2 - Xuat mang\n");
        printf("3 - In mang theo thu tu giam dan\n");
        printf("4 - Kiem tra tat ca phan tu la so le\n");
        printf("5 - Tim kiem gia tri\n");
        printf("6 - Hien thi cac so nguyen to\n");
        printf("7 - Thoat\n");
        printf("Lua chon cua ban: ");
        // Doc lua chon
        scanf("%d",&choice);

        // In ra lua chon theo so tuong ung
        printf("Ban da chon: %d\n", choice);

        switch (choice) {
            case 1:
                size = nhapMang(arr);
                break;
            case 2:
                xuatMang(arr, size);
                break;
            case 3:
                inMangGiamDan(arr, size);
                break;
            case 4:
                kiemTraTatCaLe(arr, size);
                break;
            case 5:
                timKiemGiaTri(arr, size);
                break;
            case 6:
                hienThiSoNguyenTo(arr, size);
                break;
            case 7:
                printf("Ban co chac muon thoat? Nhap 1 de xac nhan: ");
                int confirm;
                scanf("%d", &confirm);
                if(confirm == 1) {
                    printf("Tam biet!\n");
                    running = 0;
                } else {
                    printf("Huy thoat.\n");
                }
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon tu 1-7.\n");
        }
    } while (running);


    return 0;
}
