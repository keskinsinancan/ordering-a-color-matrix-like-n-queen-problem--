#include <stdio.h>
#define  x 3

/**typedef struct{
    char color[10];
}COLORS;

COLORS matrix[x][x]= {
        {"mavi", "mor", "yesil", "gri","sari","kirmizi" },
        {"mavi", "mor", "yesil", "gri","sari","kirmizi" },
        {"mavi", "mor", "yesil", "gri","sari","kirmizi" },
        {"mavi", "mor", "yesil", "gri","sari","kirmizi" },
        {"mavi", "mor", "yesil", "gri","sari","kirmizi" },
        {"mavi", "mor", "yesil", "gri","sari","kirmizi" },
    };
    */

int codes[x][x]= {
        {1,2,3},
        {2,3,1},
        {2,1,3}

};
/**COLORS matrix[x][x];*/
/**
renk kodlari:
sari    : 1;
mavi    : 2;
yesil   : 3;
mor     : 4;
beyaz   : 5;
siyah   : 6;
kirmizi : 7;
gri     : 8;

*/
//void prepare_code_matrix();
//void print_color_matrix();
void print_result(); //matrisi renk kodlarına göre ekrana yazdıran fonksiyon
void print_matrix(); //matrisin durumunu yazdýran fonksiyon
void shift_elements(int);//dizideki elemanlari shift eden fonksiyon
int place_elements(int); //dizideki elemanlarin durumuna göre recursive calisan fonksiyon
int possible(int); //bir siranın düzgün siralamada yerleşip yerleşmediğini kontrol eder
int check_codes();//matrisin doğru yerleşip yerleşmediğini kontrol eden, yerleştiyse 1, diğer durumda 0 döndüren fonksiyon
int main(){
    int result;
    printf("renk listesi ve kodlari soyledir: \n");
    printf("\nsari    :1\nmavi    :2\nyesil   :3\nmor     :4\nbeyaz   :5\nsiyah   :6\nkirmizi :7\ngri     :8\n");
    //print_color_matrix();
    //prepare_code_matrix();
    printf("Renk matrisinin ilk hali=>\n");
    print_result();
    printf("\nMatrisin ilk hali=>\n");
    print_matrix();
    printf("-----------------------------------------------\n");
    printf("\n");
    result = place_elements(1); //fonksiyon cagrilir, recursive olarak calisir, 1. satirdan karsılastırma baslar
    if(result == 0){
        printf("\n Matris cozulemiyor");
    }
    if(result == 1){
        printf("\nMatris asagidaki sekilde siralanmistir\n");
        print_result();
    }
    return 0;
}
int place_elements(int row){
    int i = 0;
    int solved = 0;
    solved = check_codes(row); //matrisin yerine yerleşip yerleşmediği kontrol ediliyor
   /** if(solved == 1){
        return 1;
    }*/
    if (row < x){ //son satıra gidene kadar kontrol edilmeli
        for(i = 0; i < x; i++){
            if(possible(row)){ //eğer satırlar uygunsa alt satıra gecilir
                if(place_elements(row+1))
                    return 1;
            }
            shift_elements(row); //eger satirlar yerlesmemisse shift edilir
        }
    } else {
        return 1; //son satirdan ileri gecildiğinde matris istenildigi gibi dizilmis demektir
    }
    return 0; //eger satırlar istenilen gibi yerlestirilemezse programdan cıkılır
}
int possible(int row){
    int result = 1;
    int m; //indis tutan degiskenler
    int n;
    int k;
    m = row; //baslangıc satırı yukardan alınır
    n = m-1; //alt satırları işaret eder
    while(m >= 1){
        while(n >= 0){
            if(codes[m][k] == codes[n][k] && k < x){
                result = 0; //eğer sutunlarda esitlik söz konusuysa donguden cikilir ve fonksiyon 0 dondurur
                return result;
            }
            else{
                k++;
                if(k == x){
                    k = 0;
                    n--;
                }
            }
        }
        m--;
    }
    return result;
}
void print_result(){ //renkkeri ekrana yazdiran fonksiyon
    int i; //indis degiskenleri
    int j;
    printf("-----------------------------------------------\n");
    printf("\n     ");
    for(i = 0; i < x; i++){
        printf("%d       ",i+1);
    }
    printf("\n-----------------------------------------------\n");
    //renkler düzgün bir formatta ekrana bastırılır
    for(i = 0; i < x ; i++){
        printf("%d  |", i+1);
        for(j = 0; j < x; j++){
            if(codes[i][j] == 1)
                printf("sari    ");
            if(codes[i][j] == 2)
                printf("mavi    ");
            if(codes[i][j] == 3)
                printf("yesil   ");
            if(codes[i][j] == 4)
                printf("mor     ");
            if(codes[i][j] == 5)
                printf("beyaz   ");
            if(codes[i][j] == 6)
                printf("siyah   ");
            if(codes[i][j] == 7)
                printf("kirmizi ");
            if(codes[i][j] == 8)
                printf("gri     ");
        }
        printf("\n \n");
    }
    printf("-----------------------------------------------\n");
}
int check_codes(){ //matrisin yerlesip yerlesmedigini kontrol eden fonksiyon
    int result = 1; //fonksiyonun dondurecegı degisken
    int m; //indis degiskenleri
    int n;
    int k;
    // işleme matrisin sonundan baslanır ve her eleman için aynı sutunda bulunan //diğer elemanlarla karşılaştırma yapılır
    m = x-1;    //üst satir
    n = m-1;    //alt satır
    k = 0; //sutun indisini tutan değişken

    while(m >= 1){
        while(n >= 0){
            if(codes[m][k] == codes[n][k] && k < x){
                result = 0; //eğer sutunlarda esitlik söz konusuysa donguden cikilir ve fonksiyon 0 dondurur
                return result;
            }
            else{
                k++;
                if(k == x){
                    k = 0;
                    n--;
                }
            }
        }
        m--;
    }
    return result; //eger sutunlarda esıtlık soz konusu degılse result = 1 doner
}
void shift_elements(int row){ //elementleri shift eden fonksiyon
    int tmp; //satırdaki son elemanı saklayan degısken
    int i;
    printf("\nshift islemi, satir=>%d", row+1);
    tmp = codes[row][x-1];
    for(i = x-2 ; i >= 0; i--){//satır sonuna kadar elemanlar kaydırılır
        codes[row][i+1] = codes[row][i];
    }
    codes[row][0] = tmp;//satırın ilk elemanı olarak gecıcı degıskene aldıgınız deger atanır
    print_matrix();
}
void print_matrix(){ //renklerin temsili kodları tutan matrisi ekrana yazdıran fonksiyon
    printf("\n");
    int i, j;
    printf("-----------------------------------------------\n");
    printf("       ");
    for(i = 0; i < x; i++){
        printf("%d   ",i+1);
    }
    printf("\n--------------------------------\n");
    for(i = 0; i < x; i++){
        printf("%d  |", i+1);
        for(j = 0; j < x; j++){
            printf("   %d", codes[i][j]);
        }
        printf("\n\n");
    }
    printf("-----------------------------------------------\n");
}
/**void prepare_code_matrix(){
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
            if(!strcmp(matrix[i][j].color,"sari"))
                codes[i][j] = 1;
            else if(!strcmp(matrix[i][j].color,"mavi"))
                codes[i][j] = 2;
            else if(!strcmp(matrix[i][j].color,"yesil"))
                codes[i][j] = 3;
            else if(!strcmp(matrix[i][j].color,"mor"))
                codes[i][j] = 4;
            else if(!strcmp(matrix[i][j].color,"beyaz"))
                codes[i][j] = 5;
            else if(!strcmp(matrix[i][j].color,"siyah"))
                codes[i][j] = 6;
            else if(!strcmp(matrix[i][j].color,"kirmizi"))
                codes[i][j] = 7;
            else if(!strcmp(matrix[i][j].color,"gri"))
                codes[i][j] = 8;
        }
        printf("\n");
    }

}
*/
/**void print_color_matrix(){
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j < x; j++){
            printf(" %s", matrix[i][j].color);
        }
        printf("\n");
    }
}
*/
