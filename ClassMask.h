//stale uzywane przy dynamicznym tworzeniu obiektow
//opis:
//dla klas abstrakcyjnych nie nalezy definiowac stalych
//
//pierwszy bajt zawiera podstawowe klasy dziedziczace z CSObject - moze byc
//ich 8
//kolejne klasy dziedziczace z bazowych definiujemy na razie na 4 bitach 
//w razie potrzeby trzeba bedzie inaczej pakowac bity

//uwaga: poniewaz zaczelo brakowac numerkow wiec zmiana - teraz wszystkie poziomy klas sa
//na 8 bitach

//wyjatek (w stosunku do tych 8 bitow) CScriptedActive i CMoveable sa razem na 8 bitach
//(zajmuja ostatnie 2 bity "swojego" bajtu)

#define GENERIC                                 0x00000000
#define VIRTUAL                                 0x80000000
#define STOREABLE                               0x00000001      //derived from GENERIC
#define EQUIPMENT                               0x00000002      //derived from GENERIC
#define OTHER                                   0x00000004
//dla klas "dziedziczacych" z OTHER nie robimy hierarchii tylko nadajemy im kolejne bity
#define LOCALPLAYER                             0x00000104      //derived from OTHER
#define PLAYER                                  0x00000204      //derived from OTHER
#define GAMEPLAYER                              0x00000404      //derived from OTHER
#define AIPLAYER                                0x00000804      //derived from OTHER
#define AIGAMEPLAYER                            0x00001004      //derived from OTHER
#define AIWORLD									0x00002004		//derived from OTHER
#define WORLD									0x00004004		//derived from OTHER
#define COMMAND									0x00008004		//derived from OTHER
#define MULTIEXPLOSION                          0x00010004      //derived from OTHER
#define EARTHCVM	                            0x00020004      //derived from OTHER
                                                
#define ACTIVE                                  0x00000101      //derived from STOREABLE
#define PASSIVE                                 0x00000201      //derived from STOREABLE
#define DYNAMIC                                 0x00000401      //derived from STOREABLE
#define MINE                                    0x00000801      //derived from STOREABLE
#define CANNON                                  0x00000102      //derived from EQUIPMENT
#define REPAIRER                                0x00000202      //derived from EQUIPMENT
#define CONTAINERTRANSPORTER                    0x00000402      //derived from EQUIPMENT
#define LOOKROUNDEQUIPMENT                      0x00000802      //derived from EQUIPMENT
#define UPGRADECOPULA                           0x00001002      //derived from EQUIPMENT
#define TRANSPORTERHOOK                         0x00002002      //derived from EQUIPMENT
#define BUILDPASSIVE                            0x00010201      //derived from PASSIVE
#define TRANSIENTPASSIVE                        0x00020201      //derived from PASSIVE
#define ARTEFACT                                0x01020201      //derived from TRANSIENTPASSIVE
#define BUILDING                                0x00010101      //derived from ACTIVE
#define PLATOON                                 0x00020101      //derived from ACTIVE
#define VERTICALVEHICLE                         0x00040101      //derived from ACTIVE
#define STARTINGPOSITIONMARK                    0x00080101      //derived from ACTIVE
#define SCRIPTEDACTIVE                          0x00400101      //derived from ACTIVE
//nie mozna zajac 0x00800101 - tam (8) jest bit MOVEABLE
#define MISSILE                                 0x00010401      //derived from DYNAMIC
#define EXPLOSION                               0x00020401      //derived from DYNAMIC
#define FLYINGWASTE                             0x00040401      //derived from DYNAMIC
#define SMOKE                                   0x00080401      //derived from DYNAMIC
#define DYNAMICLINE                             0x00100401      //derived from DYNAMIC
#define EXPLOSIONEX                             0x01020401      //derived from EXPLOSION
#define WALLLASER                               0x01100401      //derived from DYNAMICLINE
#define BUILDERLINE                             0x02100401      //derived from DYNAMICLINE
#define VERTICALVEHICLEBUILDINGTRANSPORTER      0x01040101      //derived from VERTICALVEHICLE
#define VERTICALVEHICLERESOURCETRANSPORTER      0x02040101      //derived from VERTICALVEHICLE
#define VERTICALVEHICLEUNITTRANSPORTER          0x04040101      //derived from VERTICALVEHICLE
#define MOVEABLE                                0x00C00101      //derived from SCRIPTEDACTIVE (na jednym bajcie ze SCRIPTEDACTIVE)
#define SUPPLYTRANSPORTER                       0x01C00101      //derived from MOVEABLE
#define BUILDROBOT                              0x02C00101      //derived from MOVEABLE
#define MININGROBOT                             0x04C00101      //derived from MOVEABLE
#define SAPPERROBOT                             0x08C00101      //derived from MOVEABLE
#define CONTAINERROBOT                          0x10C00101      //derived from MOVEABLE
#define REPAIRERROBOT                           0x20C00101      //derived from MOVEABLE
#define TRANSPORTERROBOT                        0x40C00101      //derived from MOVEABLE

//po zmianie tego pliku nalezy go skopiowac do katalogu z parametrami
//i przed uzyciem wygenerowac nowy plik parametrow

//powyzszych stalych nie nalezy uzywac bezposrednio ale 
//przy define DECLARE_DYNCREATE, a przy sprawdzaniu czy obiekt jest danej klasy
//nalezy uzywac makra IS_KIND_OF a przy porownywaniu identyfikatora
//IS_ID_KIND_OF
