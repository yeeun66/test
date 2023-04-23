#include "product.h"
#include "manager.h"

int main(){
    Product sp[30];
    int menu;
    int count = 0;
    int result = 0;
    int index = 0;
    int no = 0;
     index = loadData(sp);
    if (index == 0) printf("=>파일 없음\n");
    while (1) {
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1) {
            listProduct(sp, index);
        } else if (menu == 2) {
            result = createProduct(&sp[index]);
            count++;
            index ++;
        } else if (menu == 3) {
            no = selectDataNo(sp, count);
            if (no != 0) {
                result = updateProduct(&sp[no-1]);
                printf("=> 수정됨!\n");
            }
            else printf("수정을 취소함\n");
        } else if (menu == 4) {
            int n = 0;
            no = selectDataNo(sp, count);
            printf("정말로 삭제하시겠습니까? (삭제:1)");
            scanf("%d", &n);
            if (n == 1) {
                result = deleteProduct(&sp[no-1]);
            } else
                printf("=> 취소됨!\n");
        } else if (menu == 5) {
            saveData(sp, count);
        }
    }
    printf("종료됨!\n");
    return 0;
    }
