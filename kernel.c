// kernel.c - heel simpel, wordt door bootloader geladen
void kmain(void) {
    char *vidptr = (char*)0xb8000;  // video geheugen
    const char *message = "FIFI 1.0 \n WELCOME|BIENVENUE|WELKOM|WILKOMMEN|BIENVENIDO|欢迎|مرحباً \n \n \n \n \n Copyright Medyab 2023-2025 Fifi 2025 \n Codename: \n Mara";
    int i = 0;

    while(message[i] != 0) {
        vidptr[i*2] = message[i];      // karakter
        vidptr[i*2 + 1] = 0x0F;       // kleur (wit op zwart)
        i++;
    }

    // blijf hangen
    while(1);
}
