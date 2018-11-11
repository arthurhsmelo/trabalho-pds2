#ifndef PAGE_H
#define PAGE_H

class Page {    
public:
    virtual ~Page() = default;
    Page();

    /**
     * 
     * Garante que as classes filhas terão um método para 
     * mostrar as opções possíveis naquela 'tela'
     * 
     **/
    virtual void showMenu() = 0;
};

#endif