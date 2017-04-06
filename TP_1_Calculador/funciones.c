
float operando1(float num1)
{

    printf("ingrese A= ");
    scanf("%f",&num1);

    return num1;
}
float operando2(float num2)
{
    printf("ingrese B= ");
    scanf("%f",&num2);

    return num2;
}
float sumar (float num1,float num2)
{
    float resultado;

    resultado=num1+num2;

    return (resultado);
}
float restar (float num1,float num2)
{
    float resultado;

    resultado=num1-num2;

    return (resultado);
}
float multiplicacion (float num1,float num2)
{

    float resultado;

        resultado=num1*num2;

        return (resultado);


}
float division(float num1,float num2)
{
    float respuesta;

    while(num2==0)
    {
        int respuesta;

        printf("reingrese numero");
        scanf("%f",&num2);

        if(num2!=0)
        {
            respuesta=num1/num2;
             return (respuesta);
        }
    }
    respuesta=num1/num2;

    return(respuesta);
}
float factorial(float num1)
{
    float resultado;

    if(num1==0)
    {
        return 1;
    }
    else
    {
        resultado=num1*factorial(num1-1);
        return (resultado);
    }
}
