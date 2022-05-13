#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERR_ARCHIVO 1
#define ERR_PARAM 2

typedef struct
{
    char codigo[31];
    char descripcion[201];
    float precioUnitario;
    int cantidad;
} Producto;

int generarArchivoProds(const char* nombreArchivo);
int generarArchivoMovs(const char* nombreArchivo);
int mostrarArchivo(const char* nombreArchivo);
void mostrarProducto(const Producto* producto);
int actualizarArchivo();
void actualizarProducto(Producto* producto, float porcentaje);
int merge(const char* nombreArchProd, const char* nombreArchMov);

int main()
{
    int ret;

    ret = generarArchivoProds("Productos.dat");

    if (ret != TODO_OK)
        return ret;

    ret = generarArchivoMovs("Movimientos.dat");

    if (ret != TODO_OK)
        return ret;

    puts("Movimientos");
    ret = mostrarArchivo("Movimientos.dat");

    puts("Productos");
    ret = mostrarArchivo("Productos.dat");

    ret = merge("Productos.dat", "Movimientos.dat");

//    float porcentaje = 5;
//    ret = actualizarArchivo("Productos.dat", porcentaje);

    puts("Archivo Final");
    ret = mostrarArchivo("Productos.dat");

    return ret;
}

int generarArchivoProds(const char* nombreArchivo)
{
    FILE *arch = fopen(nombreArchivo, "wb");

    if (!arch)
    {
        printf("El archivo no se pudo crear.\n");
        return ERR_ARCHIVO;
    }

    Producto productos[5] =
    {
        { "coco", "Coco", 12, 540 },
        { "mandarina", "Mandarina", 64, 20 },
        { "manzana", "Manzana", 32, 120 },
        { "sandia", "Sandia", 54, 320 },
        { "uva", "Uva", 33, 650 }
    };

    fwrite(productos, sizeof(Producto), 5, arch);

    fclose(arch);

    return TODO_OK;
}

int generarArchivoMovs(const char* nombreArchivo)
{
    FILE *arch = fopen(nombreArchivo, "wb");

    if (!arch)
    {
        printf("El archivo no se pudo crear.\n");
        return ERR_ARCHIVO;
    }

    Producto productos[10] =
    {
        { "coco", "Coco", 12, 540 },
        { "durazno", "Durazno", 43, 123 },
        { "kiwi", "Kiwi", 20, 65 },
        { "mandarina", "Mandarina", 64, 20 },
        { "mango", "Mango", 133, 34 },
        { "mango", "Mango", 137, 64 },
        { "manzana", "Manzana", 32, 120 },
        { "pera", "Pera", 65, 100 },
        { "sandia", "Sandia", 54, 320 },
        { "sandia", "Sandia", 55, 32 }
    };

    fwrite(productos, sizeof(Producto), 10, arch);

    fclose(arch);

    return TODO_OK;
}

void mostrarProducto(const Producto* prod)
{
    printf("[Codigo: %s, Descripcion: %s, PrecioU: %.2f, Cant: %d]\n",
           prod->codigo,
           prod->descripcion,
           prod->precioUnitario,
           prod->cantidad);
}

int actualizarArchivo()
{
    FILE *arch = fopen("Productos.dat", "rb");

    if (!arch)
    {
        printf("El archivo no se pudo abrir.\n");
        return ERR_ARCHIVO;
    }

    Producto prod;

    fread(&prod, sizeof(Producto), 1, arch);

    while(!feof(arch))
    {
        prod.precioUnitario *= 1.10f;
        fseek(arch, -(long)sizeof(Producto), SEEK_CUR);
        fwrite(&prod, sizeof(Producto), 1, arch);
        fseek(arch, 0, SEEK_CUR);
        fread(&prod, sizeof(Producto), 1, arch);
    }

    fclose(arch);

    return TODO_OK;
}

int mostrarArchivo(const char* nombreArchivo)
{
    FILE *arch = fopen(nombreArchivo, "rb");

    if (!arch)
    {
        printf("El archivo no se pudo abrir.\n");
        return ERR_ARCHIVO;
    }

    Producto producto;
    fread(&producto, sizeof(Producto), 1, arch);

    while(!feof(arch))
    {
        mostrarProducto(&producto);
        fread(&producto, sizeof(Producto), 1, arch);
    }

    fclose(arch);

    return TODO_OK;
}
void actualizarProducto(Producto* producto, float porcentaje)
{
    producto->precioUnitario *= 1 + porcentaje / 100;
}

int merge(const char* nombreArchProd, const char* nombreArchMov)
{
    int comp;

    FILE* archProd = fopen(nombreArchProd, "rb");

    if (!archProd)
    {
        printf("El archivo no se pudo abrir1.\n");
        return ERR_ARCHIVO;
    }

    FILE* archMov = fopen(nombreArchMov, "rb");

    if (!archMov)
    {
        printf("El archivo no se pudo abrir2.\n");
        return ERR_ARCHIVO;
    }

    FILE* archTemp = fopen("Productos.tmp", "wb");

    if (!archTemp)
    {
        printf("El archivo no se pudo crear.\n");
        return ERR_ARCHIVO;
    }

    Producto prod, prodTemp, mov;

    fread(&prod, sizeof(Producto), 1, archProd);
    fread(&mov, sizeof(Producto), 1, archMov);

    while(!feof(archProd) && !feof(archMov))
    {
        comp = strcmp(prod.codigo, mov.codigo);

        if(comp == 0)
        {
            prod.cantidad += mov.cantidad;
            prod.precioUnitario = mov.precioUnitario;
            fread(&mov, sizeof(Producto), 1, archMov);
        }

        if(comp < 0)
        {
            fwrite(&prod, sizeof(Producto), 1, archTemp);
            fread(&prod, sizeof(Producto), 1, archProd);
        }

        if(comp > 0)
        {
            prodTemp = mov;
            fread(&mov, sizeof(Producto), 1, archMov);

            while(!feof(archMov) && strcmp(mov.codigo, prodTemp.codigo) == 0)
            {
                prodTemp.cantidad += mov.cantidad;
                prodTemp.precioUnitario = mov.precioUnitario;
                fread(&mov, sizeof(Producto), 1, archMov);
            }
            fwrite(&prodTemp, sizeof(Producto), 1, archTemp);
        }
    }

    while(!feof(archProd))
    {
        fwrite(&prod, sizeof(Producto), 1, archTemp);
        fread(&prod, sizeof(Producto), 1, archProd);
    }

    while(!feof(archMov))
    {
        prodTemp = mov;
        fread(&mov, sizeof(Producto), 1, archMov);

        while(!feof(archMov) && strcmp(mov.codigo, prodTemp.codigo) == 0)
        {
            prodTemp.cantidad += mov.cantidad;
            prodTemp.precioUnitario = mov.precioUnitario;
            fread(&mov, sizeof(Producto), 1, archMov);
        }
        fwrite(&prodTemp, sizeof(Producto), 1, archTemp);
    }

    fclose(archProd);
    fclose(archMov);
    fclose(archTemp);

    remove(nombreArchProd);
    rename("Productos.tmp", nombreArchProd);

    return TODO_OK;
}
