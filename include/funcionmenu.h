void Usage(int argc, char *argv[]);

int control_errores_int(void);
unsigned control_errores_unsigned(int number);
float control_errores_float(void);

void cabecera(void);
BaseSort<int>* elegir_contenedor(void);

Vector<int> elegir_vector(unsigned size);
BaseSort<int>* elegir_ordenacion(unsigned size);
BaseSort<int>* elegir_ordenacion(Vector<int>);

void visualizar_traza(BaseSort<int>* metodo_traza);