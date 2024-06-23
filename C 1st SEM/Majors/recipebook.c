#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for strings
#define MAX_NAME_LENGTH 50
#define MAX_INGREDIENTS_LENGTH 200
#define MAX_INSTRUCTIONS_LENGTH 500

// Structure to represent a recipe
struct Recipe {
    char name[MAX_NAME_LENGTH];
    char ingredients[MAX_INGREDIENTS_LENGTH];
    char instructions[MAX_INSTRUCTIONS_LENGTH];
};

// Function to add a new recipe
void addRecipe(FILE *file) {
    struct Recipe newRecipe;

    printf("Enter recipe name: ");
    fgets(newRecipe.name, sizeof(newRecipe.name), stdin);

    printf("Enter ingredients: ");
    fgets(newRecipe.ingredients, sizeof(newRecipe.ingredients), stdin);

    printf("Enter instructions: ");
    fgets(newRecipe.instructions, sizeof(newRecipe.instructions), stdin);

    // Write the new recipe to the file
    fwrite(&newRecipe, sizeof(struct Recipe), 1, file);

    printf("Recipe added successfully!\n");
}

// Function to display all recipes
void displayRecipes(FILE *file) {
    struct Recipe currentRecipe;

    // Rewind the file to the beginning
    fseek(file, 0, SEEK_SET);

    // Read and display each recipe in the file
    while (fread(&currentRecipe, sizeof(struct Recipe), 1, file) == 1) {
        printf("\nRecipe Name: %sIngredients: %sInstructions: %s\n",
               currentRecipe.name, currentRecipe.ingredients, currentRecipe.instructions);
    }
}

// Function to search for recipes based on ingredient
void searchByIngredient(FILE *file) {
    char searchIngredient[MAX_INGREDIENTS_LENGTH];
    printf("Enter ingredient to search: ");
    fgets(searchIngredient, sizeof(searchIngredient), stdin);

    struct Recipe currentRecipe;

    // Rewind the file to the beginning
    fseek(file, 0, SEEK_SET);

    // Read and display recipes containing the specified ingredient
    while (fread(&currentRecipe, sizeof(struct Recipe), 1, file) == 1) {
        if (strstr(currentRecipe.ingredients, searchIngredient) != NULL) {
            printf("\nRecipe Name: %sIngredients: %sInstructions: %s\n",
                   currentRecipe.name, currentRecipe.ingredients, currentRecipe.instructions);
        }
    }
}

// Function to remove a recipe
void removeRecipe(FILE *file) {
    char recipeName[MAX_NAME_LENGTH];
    printf("Enter the name of the recipe to remove: ");
    fgets(recipeName, sizeof(recipeName), stdin);

    FILE *tempFile = fopen("temp.txt", "w");
    struct Recipe currentRecipe;

    // Copy recipes to temp file, skipping the one to be removed
    while (fread(&currentRecipe, sizeof(struct Recipe), 1, file) == 1) {
        if (strcmp(currentRecipe.name, recipeName) != 0) {
            fwrite(&currentRecipe, sizeof(struct Recipe), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original file with the temp file
    remove("recipes.txt");
    rename("temp.txt", "recipes.txt");

    printf("Recipe removed successfully!\n");
}

// Function to edit a recipe
void editRecipe(FILE *file) {
    char recipeName[MAX_NAME_LENGTH];
    printf("Enter the name of the recipe to edit: ");
    fgets(recipeName, sizeof(recipeName), stdin);

    struct Recipe currentRecipe;

    // Rewind the file to the beginning
    fseek(file, 0, SEEK_SET);

    int found = 0;

    // Read and edit the specified recipe
    while (fread(&currentRecipe, sizeof(struct Recipe), 1, file) == 1) {
        if (strcmp(currentRecipe.name, recipeName) == 0) {
            found = 1;

            // Allow the user to edit the recipe
            printf("Enter new ingredients: ");
            fgets(currentRecipe.ingredients, sizeof(currentRecipe.ingredients), stdin);

            printf("Enter new instructions: ");
            fgets(currentRecipe.instructions, sizeof(currentRecipe.instructions), stdin);

            // Move the file pointer back by one record size
            fseek(file, -sizeof(struct Recipe), SEEK_CUR);

            // Write the updated recipe back to the file
            fwrite(&currentRecipe, sizeof(struct Recipe), 1, file);

            printf("Recipe edited successfully!\n");
            break; // Exit the loop after editing
        }
    }

    if (!found) {
        printf("Recipe not found.\n");
    }
}

int main() {
    FILE *file = fopen("recipes.txt", "a+");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    int choice;

    do {
        printf("\nRecipe Book Menu:\n");
        printf("1. Add Recipe\n");
        printf("2. Display All Recipes\n");
        printf("3. Search by Ingredient\n");
        printf("4. Remove Recipe\n");
        printf("5. Edit Recipe\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                addRecipe(file);
                break;
            case 2:
                displayRecipes(file);
                break;
            case 3:
                searchByIngredient(file);
                break;
            case 4:
                removeRecipe(file);
                break;
            case 5:
                editRecipe(file);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 5.\n");
        }
    } while (choice != 0);

    fclose(file);

    return 0;
}
