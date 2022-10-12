#include <stdio.h>

void main() {        
        int n;
        float l, b, h, r, volume=0;
        char cont = 'y';
        
        while(cont == 'y') {
                printf("To find the volume of figure:\n Press '1' for CUBE\n Press '2' for CUBOID\n Press '3' for SPHERE\n Press '4' for CYLINDER\n Press '5' for CONE\n");
                scanf("%d", &n);
                
                switch (n) {
                        case 1: printf("Enter the value of side (l): ");
                                scanf("%f", &l);
                        
                                volume= l*l*l;
                        
                                printf("The volume of the cube is: %f\n", volume);
                                break;
                                
                        case 2: printf("Enter the value of length of cuboid (l): ");
                                scanf("%f", &l); 
                                
                                printf("Enter the value of breadth of cuboid (b): ");
                                scanf("%f", &b);
                                
                                printf("Enter the value of height of cuboid (h): ");
                                scanf("%f", &h);
                                
                                volume = l*b*h;
                                
                                printf("The volume of the cuboid is: %f\n", volume);
                                break;
                                
                        case 3: printf("Enter the value of radius of sphere (r): ");
                                scanf("%f", &r);  
                                
                                volume= (4*22*r*r*r)/(21);
                                
                                printf("The volume of the sphere is: %f\n", volume);
                                break;
                                
                        case 4: printf("Enter the value of radius of cylinder (r): ");
                                scanf("%f", &r);  
                                
                                printf("Enter the value of height of cylinder (h): ");
                                scanf("%f", &h);
                                
                                volume= (22*r*r*h)/7;
                                
                                printf("The volume of the cylinder is: %f\n", volume);
                                break;
                                
                        case 5: printf("Enter the value of radius of cone (r): ");
                                scanf("%f", &r);  
                                
                                printf("Enter the value of height of cone (h): ");
                                scanf("%f", &h); 
                                
                                volume= (22*r*r*h)/21;
                                
                                printf("The volume of the cone is: %f\n", volume);
                                break;
                                
                        default:printf("Invalid input\n\n");     
                }

                printf("Do you wish to continue y or n : ");
                scanf("%s", &cont);
        }                                                                           
}