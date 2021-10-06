
// $Id: DetectorConstruction.cc 77656 2013-11-27 08:52:57Z gcosmo $
//
/// \file DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class

#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4MaterialTable.hh"
#include "G4NistManager.hh"
#include "G4MaterialPropertiesTable.hh"

#include "G4VSolid.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4PVReplica.hh"
#include "G4UserLimits.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"

#include "G4RunManager.hh"
#include "G4GenericMessenger.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4ios.hh"
#include "G4SystemOfUnits.hh"

#include "SD.hh"
#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"

#include "G4GDMLParser.hh"
#include "G4TessellatedSolid.hh"

#include <string>
#include <iostream>

using namespace std;
const G4int nEntries = 101;

const G4int NUM = 2;
G4double EN[NUM] = {0.1*eV,06*eV} ; 
G4double REFLECTIVITY[NUM] = { 0, 0 };
G4double TRANSMITTANCE[NUM] = { 1, 1 };
G4double ABSLENGTH[NUM] = {1*um,1*um};
G4double PbRI[NUM] = {1.7,1.7};

G4double PhotonEnergy[nEntries] = { 0.1850510260195518*eV,  0.1915701289139365*eV,  0.1983112402960648*eV,  0.20530582452906065*eV,  0.2125564673977365*eV,  0.2200251773435665*eV,  0.2277864917014509*eV,  0.2358010411432098*eV,  0.24411141451683346*eV,  0.2527195014942921*eV,  0.2616252108738125*eV,  0.2708260974947569*eV,  0.2803803424538664*eV,  0.29029311035612204*eV,  0.3004948798669406*eV,  0.3110491405747609*eV,  0.3220368504755837*eV,  0.3333804448322122*eV,  0.3451675596689858*eV,  0.3573031338129675*eV,  0.3698812274257152*eV,  0.3829036054141437*eV,  0.3963688856556896*eV,  0.4104077703843089*eV,  0.4248944051854*eV,  0.4398162023167779*eV,  0.4553220250940129*eV,  0.4714227659053221*eV,  0.4879346219327026*eV,  0.5052330376246932*eV,  0.5229193902703488*eV,  0.5414156656467236*eV,  0.5605071764606677*eV,  0.5801786964581175*eV,  0.6006985825247079*eV,  0.6217862960536595*eV,  0.6437392909299051*eV,  0.6662234682058018*eV,  0.6899509595609333*eV,  0.7141946280708509*eV,  0.739321332338102*eV,  0.7653344903277759*eV,  0.7922312296044709*eV,  0.8200012396369029*eV,  0.849206763240409*eV,  0.8793204782489342*eV,  0.9103097462048436*eV,  0.9421290838381436*eV,  0.9754853456577476*eV,  1.0096432201392485*eV,  1.0453978704308575*eV,  1.0818864522958092*eV,  1.1200016931625991*eV,  1.1598146626108483*eV,  1.2002341474646634*eV,  1.2428246534993956*eV,  1.2866769140006196*eV,  1.332017484240435*eV,  1.3788277072186357*eV,  1.4274025723359396*eV,  1.4777614711930835*eV,  1.5299134678319313*eV,  1.583652924167834*eV,  1.6395687309322893*eV,  1.6972510257782298*eV,  1.7571455135076492*eV,  1.8190168344058055*eV,  1.8831134178781848*eV,  1.9494369093254666*eV,  2.018300300066738*eV,  2.089386373998984*eV,  2.1630179245132544*eV,  2.239194282700013*eV,  2.317894698693208*eV,  2.399539141341198*eV,  2.4841552280725248*eV,  2.5717524877224585*eV,  2.662318819692929*eV,  2.7564292448443695*eV,  2.8534910801633995*eV,  2.9541145445103574*eV,  3.0575631919383404*eV,  3.1652843357952443*eV,  3.2774038443854008*eV,  3.3921802307277624*eV,  3.5122999272832782*eV,  3.635899924724332*eV,  3.7639401163661113*eV,  3.8964232379981056*eV,  4.033317743432002*eV,  4.175957811825522*eV,  4.3230190876255135*eV,  4.475963445238256*eV,  4.633190860728688*eV,  4.796293517721459*eV,  4.965325888390057*eV,  5.140306278320884*eV,  5.321209761077241*eV,  5.507960347983106*eV,  5.703044500142582*eV,  5.9040089253857015*eV};
G4double Si3N4PhotonEnergies[nEntries] = { 0.2252619684467655*eV,  0.2274104685126554*eV,  0.2296003470983328*eV,  0.2318328112062448*eV,  0.2341091152437683*eV,  0.2364305633735693*eV,  0.2387985120051997*eV,  0.2412143724379372*eV,  0.2436796136656834*eV,  0.2461468878957707*eV,  0.2487145184214638*eV,  0.2513362810320286*eV,  0.25401390582483035*eV,  0.2567491974178913*eV,  0.2595440390058608*eV,  0.2624003966838089*eV,  0.2653203240597041*eV,  0.2683059671783157*eV,  0.27135956978135195*eV,  0.2744834789309269*eV,  0.2776801510259792*eV,  0.28095215824405106*eV,  0.28430219544393426*eV,  0.28773308756811256*eV,  0.2912477975877372*eV,  0.2947793329365185*eV,  0.2984693968057288*eV,  0.302253016657971*eV,  0.3061337961311104*eV,  0.3101155263459222*eV,  0.3142021982592491*eV,  0.31839801600693296*eV,  0.322707411330296*eV,  0.3271350591902367*eV,  0.3316858946845899*eV,  0.33636513139744906*eV,  0.3411782813238847*eV,  0.34613117653015*eV,  0.35122999272832783*eV,  0.3564812749657841*eV,  0.3618919656541147*eV,  0.3674694351899814*eV,  0.3731092008218469*eV,  0.37904062192937854*eV,  0.3851636763998128*eV,  0.3914878037041356*eV,  0.3980230736215079*eV,  0.4047802397424085*eV,  0.4117707985157745*eV,  0.4190070545221349*eV,  0.42650219275232104*eV,  0.4342703587849377*eV,  0.4423267478883329*eV,  0.4506877042279161*eV,  0.459370831541681*eV,  0.4683951168609736*eV,  0.4777810691063573*eV,  0.4875508746877692*eV,  0.4977285725937362*eV,  0.5081319157094251*eV,  0.5191967647952249*eV,  0.5307542270252557*eV,  0.5428379484811722*eV,  0.5554847107217729*eV,  0.5687348047389895*eV,  0.5826324597420101*eV,  0.5972263363829465*eV,  0.6125700960133384*eV,  0.6287230600055767*eV,  0.6457509762140611*eV,  0.6637269134534246*eV,  0.6827323096536327*eV,  0.7028582054030595*eV,  0.7242067022961431*eV,  0.7468926953801188*eV,  0.7705667335804829*eV,  0.7963017818439289*eV,  0.823815198891028*eV,  0.853297917640053*eV,  0.8849692179378994*eV,  0.919082190015565*eV,  0.9559305122058576*eV,  0.9958569271734916*eV,  1.039263934896058*eV,  1.0866274095801902*eV,  1.1385141178429723*eV,  1.1956045075515884*eV,  1.258467188724114*eV,  1.3284494528350979*eV,  1.4068329448893648*eV,  1.4948660167964758*eV,  1.5946519283999965*eV,  1.7089481382922085*eV,  1.8406203597550432*eV,  1.9945976099276013*eV,  2.176306607567136*eV,  2.3944416267497046*eV,  2.661747261337478*eV,  2.9955106893718217*eV,  3.4259239412296134*eV,  3.999489917196765*eV};
G4double SiO2RefractiveIndex[nEntries] = { 1.1596494139777,  1.1973256716307,  1.2280888354422,  1.2537289561387,  1.2753723963511001,  1.2937460280032,  1.3096384003386001,  1.3234105439689,  1.3354823573874,  1.3461171232165,  1.3555262189157,  1.36388143366,  1.3713701305288002,  1.3780997735118001,  1.3841208059058001,  1.3895553417944,  1.3945035722002,  1.3989819997456001,  1.4030708962298999,  1.4067782146466001,  1.4101696832452,  1.4132741569442,  1.416117293379,  1.4187459519933998,  1.4211544161909,  1.4233613684394,  1.4254044329951001,  1.427296093753,  1.4290287283802,  1.4306516985468,  1.4321372109341999,  1.433529881253,  1.4348196176837,  1.4360139618555001,  1.4371349603433001,  1.4381729429416998,  1.4391480660799998,  1.4400509385522,  1.4409133669095,  1.4417121733671998,  1.4424645759259,  1.4431739285381002,  1.4438434020914999,  1.4444759883487999,  1.4450861470108998,  1.445664578157,  1.4462138519129,  1.4467363524093,  1.4472455774928998,  1.4477322458328,  1.4482096590065,  1.448668310738,  1.4491214616538,  1.4495710901503998,  1.4500069615101001,  1.4504477357319998,  1.4508853971281002,  1.4513240787777,  1.4517653834746997,  1.4522138205731001,  1.4526712743322,  1.4531396102638001,  1.4536188536247001,  1.4541161650841998,  1.4546298754538,  1.4551660299221,  1.4557246986958,  1.4563104080175,  1.4569256013293999,  1.4575758068817,  1.4582607881283998,  1.4589865613939,  1.4597562854765,  1.4605730794883,  1.4614449911601002,  1.4623764385944,  1.4633719346282,  1.4644360310913,  1.465580829975,  1.4668048202486001,  1.4681218218831997,  1.4695286500208997,  1.4710525123802,  1.4727046797948,  1.4744682820341999,  1.4763951298846998,  1.4784676522483,  1.4807144415912,  1.4831504333467,  1.4857914366573999,  1.4886832813870001,  1.4918215034661002,  1.4952627194260002,  1.498999218542,  1.5031009629038998,  1.5076095872198998,  1.5125721155557998,  1.5180417677275,  1.5240789072975,  1.530846431063,  1.5383576204905};
G4double Si3N4RefractiveIndex[nEntries] = { 1.797843087767,  1.8020034439713002,  1.8061152321586,  1.8101787943986,  1.8141944663737,  1.8181625775726002,  1.8220834514792,  1.8259574057584,  1.8297847524406001,  1.8334935204425,  1.8372294481887002,  1.8409196667773,  1.8445644675922,  1.8481641372731,  1.8517189578931998,  1.8552292071362,  1.8586951584753,  1.8621170813530001,  1.8654952413638002,  1.8688299004391,  1.8721213170358997,  1.8753697463298002,  1.8785754404128001,  1.8817386484976,  1.8848596171278997,  1.8878797739003,  1.8909177943655,  1.8939142966348002,  1.8968695188945999,  1.8997836978561002,  1.9026570690344,  1.9054898670439,  1.9082823259132,  1.9110346794217,  1.9137471614607,  1.9164200064218997,  1.9190534496168998,  1.9216477277316002,  1.9242030793202,  1.9267197453428,  1.929197969754,  1.9316380001471,  1.933994250677,  1.9363593762366,  1.9386870747281,  1.940977616017,  1.943231277958,  1.9454483475756001,  1.9476291223833,  1.9497739118598998,  1.9518830391067,  1.9539568427123999,  1.9559956788569,  1.9579999236918,  1.9599699760391998,  1.9619062604624,  1.9638092307671002,  1.9656793740058003,  1.9675172150711,  1.9692888846646002,  1.9710644669019,  1.9728095922163,  1.974524997292,  1.9762114926598,  1.9778699738446,  1.9795014344546003,  1.9811069816063003,  1.9826878541808999,  1.9842454445198,  1.9857813243255,  1.9872972757271001,  1.9887953287262,  1.9902778065687998,  1.9917473810267,  1.9932071401451001,  1.9946327529558,  1.9960842438007,  1.9975385205151999,  1.9990013850226998,  2.0004797384719,  2.0019818454036997,  2.0035176751298,  2.0050993473208,  2.0067417199434,  2.0084631742011,  2.0102866760229,  2.0122412318597003,  2.0143553731414,  2.0166885210243,  2.0193047731615,  2.0222778887066,  2.0257264818369,  2.0298173905897,  2.0347606435188,  2.0409071028311003,  2.0487351006665,  2.0590472271638998,  2.0731921339333,  2.0934554672447,  2.1244526847835004,  2.1759394676161};
G4double NBK7Energies[nEntries] = { 1.178556915*eV,  1.1853172790000002*eV,  1.192155648*eV,  1.199073379*eV,  1.2072462259999999*eV,  1.214340719*eV,  1.221519088*eV,  1.228782829*eV,  1.236133474*eV,  1.244071718*eV,  1.251733341*eV,  1.259617875*eV,  1.267472781*eV,  1.2755574840000001*eV,  1.28361308*eV,  1.291905673*eV,  1.3001697509999999*eV,  1.308678356*eV,  1.317159114*eV,  1.325892284*eV,  1.334598358*eV,  1.3435651000000002*eV,  1.35250559*eV,  1.361715403*eV,  1.370899905*eV,  1.380362808*eV,  1.3899572580000001*eV,  1.399528022*eV,  1.409391695*eV,  1.419232915*eV,  1.429377305*eV,  1.439500609*eV,  1.4499378719999998*eV,  1.460355565*eV,  1.471098569*eV,  1.481823682*eV,  1.492886062*eV,  1.503932405*eV,  1.515328617*eV,  1.5267108409999999*eV,  1.538456228*eV,  1.55018989*eV,  1.562300749*eV,  1.57440238*eV,  1.5868960380000001*eV,  1.599383223*eV,  1.61227812*eV,  1.6251695819999998*eV,  1.638485363*eV,  1.6518010580000002*eV,  1.6655586709999999*eV,  1.679547378*eV,  1.693541694*eV,  1.708006439*eV,  1.72248107*eV,  1.7374465730000002*eV,  1.7524266769999999*eV,  1.7679193990000002*eV,  1.783431925*eV,  1.799480224*eV,  1.81555407*eV,  1.832188376*eV,  1.84885457*eV,  1.866107577*eV,  1.883399475*eV,  1.901306355*eV,  1.9192598669999998*eV,  1.937858509*eV,  1.9565123469999999*eV,  1.9758436240000001*eV,  1.9952395790000002*eV,  2.01534765*eV,  2.035530905*eV,  2.05646355*eV,  2.077483033*eV,  2.0992920319999997*eV,  2.121563782*eV,  2.1439423730000002*eV,  2.167176847*eV,  2.1905333469999997*eV,  2.214794345*eV,  2.2391942830000002*eV,  2.264551369*eV,  2.290066262*eV,  2.31659543*eV,  2.343303486*eV,  2.371087922*eV,  2.399074834*eV,  2.428205786*eV,  2.457565658*eV,  2.488143436*eV,  2.518979834*eV,  2.5511149680000003*eV,  2.5835421430000003*eV,  2.617356712*eV,  2.651501014*eV,  2.6871302000000004*eV,  2.723131725*eV,  2.760725616*eV,  2.798740123*eV,  2.83846583*eV};
G4double NBK7RefractiveIndex[nEntries] = { 1.48125165,  1.481299549,  1.48134829,  1.481397892,  1.4814568780000001,  1.4815084180000002,  1.481560886,  1.481614305,  1.4816686980000002,  1.4817278180000002,  1.4817852519999999,  1.481844739,  1.481904389,  1.4819661880000001,  1.4820281709999998,  1.4820924030000002,  1.482156843,  1.482223638,  1.482290668,  1.482360165,  1.482429924,  1.482502271,  1.482574911,  1.482650267,  1.48272595,  1.482804485,  1.48288469,  1.4829652780000002,  1.4830489409999998,  1.483133029,  1.4832203519999998,  1.483308146,  1.483399347,  1.483491069,  1.4835863809999998,  1.483682271,  1.483781947,  1.483882261,  1.4839865730000001,  1.48409159,  1.4842008309999999,  1.484310851,  1.484425338,  1.484540685,  1.4846607630000002,  1.484781788,  1.4849078269999998,  1.485034913,  1.485167317,  1.4853008769999998,  1.485440085,  1.4855829,  1.4857270569999999,  1.48587741,  1.4860292430000002,  1.486187678,  1.486347747,  1.4865148559999999,  1.486683772,  1.486860204,  1.4870386359999999,  1.487225104,  1.487413785,  1.48761107,  1.4878108069999998,  1.488019769,  1.4882314490000002,  1.488453037,  1.48867764,  1.4889128980000002,  1.4891515069999999,  1.489401595,  1.489655409,  1.489921611,  1.490191963,  1.4904757069999999,  1.490768885,  1.491066957,  1.49138014,  1.491698793,  1.492033863,  1.4923750569999998,  1.492734124,  1.4931000630000002,  1.4934855009999999,  1.4938786640000001,  1.494293153,  1.4947163430000001,  1.495162916,  1.495619311,  1.496101411,  1.496594626,  1.4971161780000002,  1.4976503419999998,  1.498215835,  1.49879568,  1.499410273,  1.5000412440000002,  1.500710884,  1.5013992790000001,  1.5021308580000001};
G4double SiO2AbsorptionEnergy[2] = {0.18*eV,5.9*eV};

const G4int nEQE = 123;

G4double EQEEnergy[nEQE] = {3.0017293463705066 *eV,2.94086918006821 *eV,2.8824278556165854 *eV,2.8262639801976728 *eV,2.772246970482326 *eV,2.72025603902032 *eV,2.6701792925867265 *eV,2.621912928318439 *eV,2.5753605154869246 *eV,2.5341164060788595 *eV,2.4977516675113605 *eV,2.4624158368693947 *eV,2.428065855257966 *eV,2.394661033363137 *eV,2.362162890663134 *eV,2.3305350075566214 *eV,2.2997428892134817 *eV,2.2697538400780397 *eV,2.240536848064918 *eV,2.2120624775852042 *eV,2.184302770627283 *eV,2.1572311551935086 *eV,2.1308223604623824 *eV,2.105052338106872 *eV,2.0798981892539246 *eV,2.0553380966188977 *eV,2.0313512613921367 *eV,2.0079178444939734 *eV,1.9850189118493917 *eV,1.9626363833651101 *eV,1.9407529853200949 *eV,1.9193522059060286 *eV,1.8984182536772325 *eV,1.8779360186903296 *eV,1.857891036132655 *eV,1.8363300648697845 *eV,1.813372612366108 *eV,1.790982091679629 *eV,1.769137758469721 *eV,1.7478198682626664 *eV,1.7270096169275557 *eV,1.7066890853544596 *eV,1.686841187992783 *eV,1.667449624939173 *eV,1.6484988372925897 *eV,1.6299739655195382 *eV,1.611860810595314 *eV,1.5941457977076838 *eV,1.5768159423280217 *eV,1.5598588184716744 *eV,1.5432625289845108 *eV,1.5270156777063404 *eV,1.5111073433743274 *eV,1.495527055140819 *eV,1.480264769590261 *eV,1.4665454595927907 *eV,1.455508298620827 *eV,1.4458360295974422 *eV,1.4374776357507026 *eV,1.4303898364059577 *eV,1.4243699771313298 *eV,1.42570334067551 *eV,1.4141203636473298 *eV,1.4095397007539108 *eV,1.4027240792150273 *eV,1.396534072370843 *eV,1.3892886778124822 *eV,1.3835462680567072 *eV,1.377560339036728 *eV,1.3726355438191973 *eV,1.3663858141819774 *eV,1.3631754742956286 *eV,1.358918414108745 *eV,1.3546878598897656 *eV,1.350483564853627 *eV,1.3463052852693944 *eV,1.3421527804131592 *eV,1.338025812521806 *eV,1.3339241467476357 *eV,1.3298475511138144 *eV,1.3257957964706368 *eV,1.3217686564525923 *eV,1.3177659074362074 *eV,1.3137873284986483 *eV,1.3098327013770807 *eV,1.3059018104287512 *eV,1.3019944425917902 *eV,1.29811038734672 *eV,1.29424943667864 *eV,1.2904113850400947 *eV,1.286596029314595 *eV,1.2828031687807857 *eV,1.2790326050772451 *eV,1.2752841421679044 *eV,1.2715575863080733 *eV,1.2678527460110558 *eV,1.2641694320153547 *eV,1.2605074572524413 *eV,1.256866636815083 *eV,1.2532467879262228 *eV,1.2496477299083901 *eV,1.2460692841536407 *eV,1.241802108969409 *eV,1.238092233478162 *eV,1.2345795685257812 *eV,1.2310867791635873 *eV,1.2276136971754428 *eV,1.225021718524322 *eV,1.2207259918947644 *eV,1.2157805395146422 *eV,1.2107065451597188 *eV,1.2055077198191888 *eV,1.199691480577776 *eV,1.1947506183884884 *eV,1.1890374701041784 *eV,1.1825746991797204 *eV,1.1761818026167867 *eV,1.169071913238305 *eV,1.160497924052679 *eV,1.1512867756022431 *eV,1.142220697849761 *eV,1.1347739945290987 *eV};
G4double EQE[nEQE] = {41.80435938330675,42.88943018703785,44.110134841235336,45.33083949543281,46.44981876178049,47.56879802812818,48.78950268232565,49.97629887390653,51.02746121502103,52.22782079164855,53.367145135566204,54.506469479483854,55.645793823401476,56.8054632448891,57.985477743946646,59.124802087864296,60.26412643178194,61.4441409308395,62.62415542989706,63.78382485138466,64.96383935044223,66.14385384949979,67.34421342612731,68.48353777004496,69.70424242424244,70.8435667681601,72.02358126721764,73.2035957662752,74.38361026533276,75.56362476439031,76.72329418587793,77.92365376250544,79.11044995408632,80.2226475279107,81.3823169493983,82.56233144845586,83.69826494611183,84.76638151853464,85.74972693441595,86.69916388768064,87.54687545309555,88.34372432458557,89.0727562708424,89.73397129186606,90.25955246242329,90.73427093905563,91.14117249045479,91.41244019138756,91.61589096708715,91.68370789232034,91.44634865400415,90.9716301773718,90.37823208158136,89.59833744139965,88.49631240636026,87.28238944468609,85.99556328838626,84.62227055241411,83.27440916340439,82.05370450920691,80.16451873485367,81.23990140640859,79.29186022908512,78.05250592044851,76.69616741578464,75.26353487023344,73.81394809337394,72.26772219805713,70.83000338311345,69.62286211396261,68.14275772074815,66.93053018220482,65.67591706539076,64.17546759460636,62.725880817746855,61.22543134696245,59.801275917065404,58.453414528055674,57.02925909815863,55.60510366826156,54.18094823836452,52.782224155429894,51.35806872553285,49.93391329563578,48.50975786573874,47.085602435841686,45.661447005944616,44.23729157604756,42.813136146150505,41.43984341017834,40.06655067420617,38.642395244309135,37.21823981441207,35.92124111932725,34.59881107727999,33.352675076120065,32.15740176888502,30.93669711468755,29.71599246049007,28.495287806292595,27.274583152095122,26.05387849789764,24.741620994635355,23.459881107728012,22.23917645353053,21.018471799333057,19.797767145135566,18.81442172925428,17.50894591851531,15.952547484413529,14.324941278816896,12.753284036537636,11.252834565753233,10.06603837417235,8.83685660432073,7.565289256198355,6.395447295925777,5.251036682615633,4.165965878884548,3.2334831569281453,2.555313904596204,2.072118312309712};
G4double acrylicEnergies[nEntries] = { 1.178556915*eV,  1.1853172790000002*eV,  1.192155648*eV,  1.199073379*eV,  1.2072462259999999*eV,  1.214340719*eV,  1.221519088*eV,  1.228782829*eV,  1.236133474*eV,  1.244071718*eV,  1.251733341*eV,  1.259617875*eV,  1.267472781*eV,  1.2755574840000001*eV,  1.28361308*eV,  1.291905673*eV,  1.3001697509999999*eV,  1.308678356*eV,  1.317159114*eV,  1.325892284*eV,  1.334598358*eV,  1.3435651000000002*eV,  1.35250559*eV,  1.361715403*eV,  1.370899905*eV,  1.380362808*eV,  1.3899572580000001*eV,  1.399528022*eV,  1.409391695*eV,  1.419232915*eV,  1.429377305*eV,  1.439500609*eV,  1.4499378719999998*eV,  1.460355565*eV,  1.471098569*eV,  1.481823682*eV,  1.492886062*eV,  1.503932405*eV,  1.515328617*eV,  1.5267108409999999*eV,  1.538456228*eV,  1.55018989*eV,  1.562300749*eV,  1.57440238*eV,  1.5868960380000001*eV,  1.599383223*eV,  1.61227812*eV,  1.6251695819999998*eV,  1.638485363*eV,  1.6518010580000002*eV,  1.6655586709999999*eV,  1.679547378*eV,  1.693541694*eV,  1.708006439*eV,  1.72248107*eV,  1.7374465730000002*eV,  1.7524266769999999*eV,  1.7679193990000002*eV,  1.783431925*eV,  1.799480224*eV,  1.81555407*eV,  1.832188376*eV,  1.84885457*eV,  1.866107577*eV,  1.883399475*eV,  1.901306355*eV,  1.9192598669999998*eV,  1.937858509*eV,  1.9565123469999999*eV,  1.9758436240000001*eV,  1.9952395790000002*eV,  2.01534765*eV,  2.035530905*eV,  2.05646355*eV,  2.077483033*eV,  2.0992920319999997*eV,  2.121563782*eV,  2.1439423730000002*eV,  2.167176847*eV,  2.1905333469999997*eV,  2.214794345*eV,  2.2391942830000002*eV,  2.264551369*eV,  2.290066262*eV,  2.31659543*eV,  2.343303486*eV,  2.371087922*eV,  2.399074834*eV,  2.428205786*eV,  2.457565658*eV,  2.488143436*eV,  2.518979834*eV,  2.5511149680000003*eV,  2.5835421430000003*eV,  2.617356712*eV,  2.651501014*eV,  2.6871302000000004*eV,  2.723131725*eV,  2.760725616*eV,  2.798740123*eV,  2.83846583*eV};
G4double acrylicRefractiveIndex[nEntries] = { 1.48125165,  1.481299549,  1.48134829,  1.481397892,  1.4814568780000001,  1.4815084180000002,  1.481560886,  1.481614305,  1.4816686980000002,  1.4817278180000002,  1.4817852519999999,  1.481844739,  1.481904389,  1.4819661880000001,  1.4820281709999998,  1.4820924030000002,  1.482156843,  1.482223638,  1.482290668,  1.482360165,  1.482429924,  1.482502271,  1.482574911,  1.482650267,  1.48272595,  1.482804485,  1.48288469,  1.4829652780000002,  1.4830489409999998,  1.483133029,  1.4832203519999998,  1.483308146,  1.483399347,  1.483491069,  1.4835863809999998,  1.483682271,  1.483781947,  1.483882261,  1.4839865730000001,  1.48409159,  1.4842008309999999,  1.484310851,  1.484425338,  1.484540685,  1.4846607630000002,  1.484781788,  1.4849078269999998,  1.485034913,  1.485167317,  1.4853008769999998,  1.485440085,  1.4855829,  1.4857270569999999,  1.48587741,  1.4860292430000002,  1.486187678,  1.486347747,  1.4865148559999999,  1.486683772,  1.486860204,  1.4870386359999999,  1.487225104,  1.487413785,  1.48761107,  1.4878108069999998,  1.488019769,  1.4882314490000002,  1.488453037,  1.48867764,  1.4889128980000002,  1.4891515069999999,  1.489401595,  1.489655409,  1.489921611,  1.490191963,  1.4904757069999999,  1.490768885,  1.491066957,  1.49138014,  1.491698793,  1.492033863,  1.4923750569999998,  1.492734124,  1.4931000630000002,  1.4934855009999999,  1.4938786640000001,  1.494293153,  1.4947163430000001,  1.495162916,  1.495619311,  1.496101411,  1.496594626,  1.4971161780000002,  1.4976503419999998,  1.498215835,  1.49879568,  1.499410273,  1.5000412440000002,  1.500710884,  1.5013992790000001,  1.5021308580000001};

const G4int SiN = 2;//77;
G4double SiReflectivity[SiN] = {0,0};//{0.6726125940000001, 0.705174, 0.732089553, 0.722956411, 0.6842353609999999, 0.623487589, 0.590475835, 0.574130338, 0.565677412, 0.5617493179999999, 0.565380276, 0.582911002, 0.5842708010000001, 0.546502292, 0.510973644, 0.48602102799999997, 0.46685326, 0.451521581, 0.439123249, 0.428907265, 0.4195857, 0.41148595, 0.40428139399999996, 0.397879181, 0.39196473299999995, 0.387105531, 0.38226452200000005, 0.37799909200000004, 0.37414201399999997, 0.37042852200000004, 0.36733593600000003, 0.364216221, 0.361451749, 0.358667135, 0.356344975, 0.354106672, 0.351853614, 0.349785241, 0.348201339, 0.34641148, 0.34471392799999995, 0.34330931600000003, 0.341798625, 0.340281901, 0.33896242200000004, 0.337639002, 0.336413285, 0.335285625, 0.33425759, 0.333329999, 0.332400673, 0.331468652, 0.33053483, 0.329598359, 0.328764393, 0.32803286800000003, 0.32730030600000004, 0.326671301, 0.326041006, 0.325409976, 0.324777931, 0.32414465, 0.32351056899999997, 0.32287546899999997, 0.32223919, 0.32160204600000003, 0.320963878, 0.32032468399999997, 0.319684464, 0.319150064, 0.318615045, 0.31807931100000003, 0.317542859, 0.317113181, 0.316683043, 0.316252445};
G4double SiEnergies[SiN] = {1*eV,5*eV};//{4.959367895856286*eV, 4.768622976784892*eV, 4.592007310978044*eV, 4.428007049871685*eV, 4.275317151600247*eV, 4.1328065798802385*eV, 3.99949023859378*eV, 3.8745061686377245*eV, 3.7570968908002174*eV, 3.646594041070799*eV, 3.5424056398973476*eV, 3.4440054832335325*eV, 3.3509242539569506*eV, 3.2627420367475573*eV, 3.1790819845232607*eV, 3.0996049349101793*eV, 3.0240048145465166*eV, 2.9520046999144567*eV, 2.8833534278234225*eV, 2.8178226681001632*eV, 2.755204386586826*eV, 2.69530863905233*eV, 2.6379616467320672*eV, 2.583004112425149*eV, 2.5302897427838196*eV, 2.479683947928143*eV, 2.4310626940471995*eV, 2.384311488392446*eV, 2.339324479177494*eV, 2.296003655489022*eV, 2.2542581344801307*eV, 2.2140035249358423*eV, 2.1751613578317044*eV, 2.1376585758001236*eV, 2.101427074515376*eV, 2.0664032899401192*eV, 2.0325278261706092*eV, 1.99974511929689*eV, 1.9680031332763044*eV, 1.9372530843188622*eV, 1.9074491907139566*eV, 1.8785484454001087*eV, 1.8505104089015998*eV, 1.8232970205353995*eV, 1.7968724260348863*eV, 1.7712028199486738*eV, 1.7462563013578474*eV, 1.7220027416167663*eV, 1.698413662964482*eV, 1.6754621269784753*eV, 1.6531226319520957*eV, 1.6313710183737786*eV, 1.6101843817715216*eV, 1.5895409922616304*eV, 1.5694202202076857*eV, 1.5498024674550896*eV, 1.5306691036593476*eV, 1.5120024072732583*eV, 1.4937855108000864*eV, 1.4760023499572283*eV, 1.45863761642832*eV, 1.4416767139117113*eV, 1.4251057172000823*eV, 1.4089113340500816*eV, 1.3930808696225525*eV, 1.377602193293413*eV, 1.3624637076528259*eV, 1.347654319526165*eV, 1.3331634128645933*eV, 1.3189808233660336*eV, 1.305096814699023*eV, 1.2915020562125745*eV, 1.2781876020248162*eV, 1.2651448713919098*eV, 1.252365630266739*eV, 1.2398419739640716*eV};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(), 
  fMessenger(0),
  fVisAttributes()
  //filename("out.csv")

{
	fMessenger = new G4GenericMessenger(this, 
                               "/detector/", 
                               "Primary detector control");
	//Z-Position Command
	G4GenericMessenger::Command& zPosCMD = fMessenger->DeclareMethodWithUnit("zpos", "mm", &DetectorConstruction::zPos, "Z position of the detector.");
	zPosCMD.SetParameterName("z",true);
	zPosCMD.SetDefaultValue("100.");

	fMessenger->DeclareMethod("outName",&DetectorConstruction::filenameChange,"Change the name of the output file.");

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
    delete fMessenger;
    
    for (G4int i=0; i<G4int(fVisAttributes.size()); ++i) 
    {
      delete fVisAttributes[i];
    }  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    // Construct materials
    ConstructMaterials();
    G4Material* air = G4Material::GetMaterial("G4_AIR");
    G4bool checkOverlaps = true;

    
    // geometries --------------------------------------------------------------
    // experimental hall (world volume)
    G4VSolid* worldSolid 
      = new G4Box("worldBox",10.*m,3.*m,10.*m);
    G4LogicalVolume* worldLogical
      = new G4LogicalVolume(worldSolid,air,"worldLogical");
    G4VPhysicalVolume* worldPhysical
      = new G4PVPlacement(0,G4ThreeVector(),worldLogical,"worldPhysical",0,
                          false,0,checkOverlaps);
    

	//Creating the bilayers for the simulation
	//double layerHeights[40] = {243,175,247,177,250,180,254,182,257,185,261,187,265,190,268,193,272,195,276,198,280,201,283,203,287,206,291,209,295,212,300,215,304,218,308,221,312,224,317,227};
	const int numlayers = 46;
	double layerHeights[numlayers] = {264,205,264,297,291,209,272,235,284,186,240,203,268,207,281,202,306,244,270,219,282,217,274,209,260,178,318,222,299,228,276,209,250,216,277,251,257,234,278,229,271,217,282,221,283,229};

	double pos[numlayers]; for(int i=0;i<numlayers;i++)pos[i]=0;
	for(int i=1;i<numlayers;i++)pos[i]+=pos[i-1]+(layerHeights[i]+layerHeights[i-1])/2;
	

	G4Material* sio2 = G4Material::GetMaterial("SiO2");
	G4Material* si3n4 = G4Material::GetMaterial("Si3N4");

	G4VSolid* layer[numlayers];
	G4LogicalVolume* layerLogical[numlayers];
	G4VPhysicalVolume* layerPhysical[numlayers];

	for(int i=0;i<numlayers;i++){
		cout << "\tObject " << i << ": " << pos[i] << " nm" <<endl;  

		layer[i] = new G4Tubs("Solid Layer "+std::to_string(i),0,5.08/2*cm,layerHeights[i]*nm/2,0,2*M_PI);
		layerLogical [i] = new G4LogicalVolume(layer[i],sio2,"Logical Layer "+ std::to_string(i));
    	layerPhysical[i] = new G4PVPlacement(0,G4ThreeVector(0,0,pos[i]*nm),layerLogical[i],"Physical Layer "+std::to_string(i), worldLogical, false, 0, checkOverlaps);
		G4VisAttributes* visAttributesSiO2 = new G4VisAttributes(G4Colour(0.,0.,1.0));
		layerLogical[i]->SetVisAttributes(visAttributesSiO2);

		

		//Optical Boundary Between layer i-1 and layer i
		G4OpticalSurface* OpRefSurface = new G4OpticalSurface("RefSurface"+std::to_string(i));
		OpRefSurface->SetType(dielectric_dielectric);
		OpRefSurface->SetModel(unified);
		OpRefSurface->SetFinish(polished);
		OpRefSurface->SetSigmaAlpha(0.1);
		
				
		G4double n[nEntries];
		for (int j =0;j<nEntries;j++) n[j] = SiO2RefractiveIndex[j]/Si3N4RefractiveIndex[j];
		if(i==0)for (int j =0;j<nEntries;j++) n[j] = SiO2RefractiveIndex[j];

		G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();
		SMPT->AddProperty("RINDEX",PhotonEnergy,n,nEntries);
		OpRefSurface->SetMaterialPropertiesTable(SMPT);
		G4VPhysicalVolume* in;
		if (i==0) in = worldPhysical;
		else in = layerPhysical[i-1];
		new G4LogicalBorderSurface("RefSurface"+std::to_string(i),in,layerPhysical[i],OpRefSurface);



		i++;
		
		layer[i] = new G4Tubs("Solid Layer "+std::to_string(i),0,5.08/2*cm,layerHeights[i]*nm/2,0,2*M_PI);		
		layerLogical [i] = new G4LogicalVolume(layer[i],si3n4,"Logical Layer "+ std::to_string(i));
    	layerPhysical[i] = new G4PVPlacement(0,G4ThreeVector(0,0,pos[i]*nm),layerLogical[i],"Physical Layer "+std::to_string(i), worldLogical, false, 0, checkOverlaps);
		G4VisAttributes* visAttributesSi3N4 = new G4VisAttributes(G4Colour(1.,0.,0.));
		layerLogical[i]->SetVisAttributes(visAttributesSi3N4);


		//Optical Boundary Between layer i and layer i+1
		G4OpticalSurface* OpRefSurface2 = new G4OpticalSurface("RefSurface"+std::to_string(i));
		OpRefSurface->SetType(dielectric_dielectric);
		OpRefSurface->SetModel(unified);
		OpRefSurface->SetFinish(polished);
		OpRefSurface->SetSigmaAlpha(0.1);
		
		for (int j =0;j<nEntries;j++) n[j] = Si3N4RefractiveIndex[j]/SiO2RefractiveIndex[j];

		G4MaterialPropertiesTable* SMPT2 = new G4MaterialPropertiesTable();
		SMPT2->AddProperty("RINDEX",Si3N4PhotonEnergies,n,nEntries);
		OpRefSurface->SetMaterialPropertiesTable(SMPT2);
		new G4LogicalBorderSurface("RefSurface"+std::to_string(i),layerPhysical[i-1],layerPhysical[i],OpRefSurface2);

	}

	//Add the lens
	G4GDMLParser parser;
	parser.Read("FRP_Glass.gdml",false); //Fresnel
	//parser.Read("lensN-BK7.gdml",false); //Lens 
	G4LogicalVolume* lensLogical = parser.GetVolume("lens"); //Fresnel
	//G4LogicalVolume* lensLogical = parser.GetVolume("lensN-BK7"); //Lens
	lensLogical->SetVisAttributes(G4Colour(0.,5.,0.,0.5));
	G4Material* acrylic = G4Material::GetMaterial("acrylic"); //Fresnel
	//G4Material* acrylic = G4Material::GetMaterial("NBK7"); //Lens
	lensLogical->SetMaterial(acrylic);
	G4RotationMatrix* rm = new G4RotationMatrix();
  	rm->rotateX(90*deg); rm->rotateY(90*deg);
	G4double zLens = 1.5*mm; //Fresnel Lens
	//G4double zLens = 12.5198*mm; // Lens
	G4VPhysicalVolume* lensPhysical = new G4PVPlacement(rm,G4ThreeVector(0,0,pos[39]*nm+layerHeights[39]*nm+zLens/2),lensLogical,"Physical Lens", worldLogical, false, 0, checkOverlaps);


	//Optical Boundary Between air and lens
	G4OpticalSurface* OpRefSurface = new G4OpticalSurface("RefSurface");
	OpRefSurface->SetType(dielectric_dielectric);
	OpRefSurface->SetModel(unified);
	OpRefSurface->SetFinish(polished);
	OpRefSurface->SetSigmaAlpha(0.1);

	G4MaterialPropertiesTable* SMPT1 = new G4MaterialPropertiesTable();
	SMPT1->AddProperty("RINDEX",acrylicEnergies,acrylicRefractiveIndex,nEntries); //Fresnel Lens
	//SMPT1->AddProperty("RINDEX",NBK7Energies,NBK7RefractiveIndex,nEntries); //Lens
	OpRefSurface->SetMaterialPropertiesTable(SMPT1);
	
	new G4LogicalBorderSurface("RefSurface",layerPhysical[39],lensPhysical,OpRefSurface);



	//Detector As a led Block
    G4Material* material = G4Material::GetMaterial("G4_Pb");
    //G4VSolid* box = new G4Box("Box",5.0*mm,5.0*mm,5.0*mm);
	G4double diameter = 200*mm;
	G4VSolid* box = new G4Tubs("Box",0,diameter,2.5*mm/2,0,2*M_PI);
    G4LogicalVolume* boxLogical = new G4LogicalVolume(box,material,"boxLogical");
	//G4double zpos = 25*mm;
	cout << "\t\t\t\t\tfzPos: "<< fzPos << endl;
    boxPhysical = new G4PVPlacement(0,G4ThreeVector(0,0,fzPos),boxLogical,"boxPhysical", worldLogical, false, 0, checkOverlaps);

	G4VisAttributes* BvisAttributes = new G4VisAttributes(G4Colour(0,0.5,1.0));
    boxLogical->SetVisAttributes(BvisAttributes);
    fVisAttributes.push_back(BvisAttributes);
    // visualization attributes ------------------------------------------------
    
    G4VisAttributes* visAttributes = new G4VisAttributes(G4Colour(0,0.5,1.0));
    visAttributes->SetVisibility(false);
    worldLogical->SetVisAttributes(visAttributes);
    fVisAttributes.push_back(visAttributes);
    
	//Optical Boundary Between air and box
	G4OpticalSurface* DetectorSurface = new G4OpticalSurface("DetectorSurface");
	DetectorSurface->SetType(dielectric_metal);
	DetectorSurface->SetModel(glisur);
	DetectorSurface->SetFinish(polished);
	//DetectorSurface->SetSigmaAlpha(0.1);

	G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();
	//SMPT->AddProperty("RINDEX",PhotonEnergy,SiO2RefractiveIndex,nEntries);
	SMPT->AddProperty("REFLECTIVITY", SiEnergies, SiReflectivity,SiN);
	//SMPT->AddProperty("ABSLENGTH", EN, ABSLENGTH,NUM);
	SMPT->AddProperty("EFFICIENCY",EQEEnergy,EQE,nEQE);
	DetectorSurface->SetMaterialPropertiesTable(SMPT);
	new G4LogicalBorderSurface("DetectorSurface",worldPhysical,boxPhysical,DetectorSurface);
    
	//Sensitive Detector
	G4SDManager* SDman = G4SDManager::GetSDMpointer(); 
	G4String SDName;

	G4cout << "\n\n\t\t\t\t\t\tSetting sensitive Detector\n\n";
	G4VSensitiveDetector* detector = new SD("/detector",filename);
	SDman->AddNewDetector(detector);
	boxLogical->SetSensitiveDetector(detector);
	

    // return the world physical volume ----------------------------------------
    
    return worldPhysical;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::ConstructMaterials()
{
    G4NistManager* nistManager = G4NistManager::Instance();

    // Air 
	nistManager->FindOrBuildMaterial("G4_AIR");

	//Air Optical Properties
	const G4int NUMENTRIES = 2;
	G4double RINDEX_AIR[NUMENTRIES] = {1.00, 1.00}; 

	// Air refractive index at 20 oC and 1 atm (from PDG) 
	for(G4int j=0 ; j<NUMENTRIES ; j++){
	RINDEX_AIR[j] = RINDEX_AIR[j] + 2.73*std::pow(10.0,-4); 
	}

	G4MaterialPropertiesTable *MPT_Air = new G4MaterialPropertiesTable();
	MPT_Air->AddProperty("RINDEX", SiO2AbsorptionEnergy, RINDEX_AIR, NUMENTRIES);
	G4Material::GetMaterial("G4_AIR")->SetMaterialPropertiesTable(MPT_Air);


    //Silicon Dioxide
    G4Element* el_si = new G4Element("Silicon", "Si",14,28.085*g/mole);
    G4Element* el_o = new G4Element("Oxygen", "O", 8,15.999*g/mole);
    G4Material* mat_sio2 = new G4Material("SiO2",2.648*g/cm3,2);
    mat_sio2->AddElement(el_si,1);
    mat_sio2->AddElement(el_o,2);

	//Optical Properites of SiO2
	G4double SiO2AbsorptionLength[2] = {10.*m,10.*m};


	G4MaterialPropertiesTable* SiO2MPT = new G4MaterialPropertiesTable();

	SiO2MPT->AddProperty("RINDEX",PhotonEnergy,SiO2RefractiveIndex,nEntries);
	//SiO2MPT->AddProperty("ABSLENGTH",SiO2AbsorptionEnergy,SiO2AbsorptionLength,2);
	//SiO2MPT->AddConstProperty("FASTTIMECONSTANT",20.*ns);
	//SiO2MPT->AddConstProperty("SLOWTIMECONSTANT",45.*ns);
	//SiO2MPT->AddConstProperty("YIELDRATIO",1.0);
	//SiO2MPT->AddConstProperty("SCINTILLATIONYIELD",100./MeV);

	mat_sio2->SetMaterialPropertiesTable(SiO2MPT);


	//NBK7
    G4Material* mat_nbk7 = new G4Material("NBK7",2.648*g/cm3,2);
    mat_nbk7->AddElement(el_si,1);
    mat_nbk7->AddElement(el_o,2);

	G4MaterialPropertiesTable* NBK7MPT = new G4MaterialPropertiesTable();

	NBK7MPT->AddProperty("RINDEX",NBK7Energies,NBK7RefractiveIndex,nEntries);
	//SiO2MPT->AddProperty("ABSLENGTH",SiO2AbsorptionEnergy,SiO2AbsorptionLength,2);
	//SiO2MPT->AddConstProperty("FASTTIMECONSTANT",20.*ns);
	//SiO2MPT->AddConstProperty("SLOWTIMECONSTANT",45.*ns);
	//SiO2MPT->AddConstProperty("YIELDRATIO",1.0);
	//SiO2MPT->AddConstProperty("SCINTILLATIONYIELD",100./MeV);

	mat_nbk7->SetMaterialPropertiesTable(NBK7MPT);


	//Optical Grade Acrylic
  	G4Element* el_h  = new G4Element("Hydrogen", "H", 1., 1.01*g/mole);
	G4Element* el_c  = new G4Element("Carbon",   "C", 6., 12.01*g/mole);
    G4Material* mat_acrylic = new G4Material("acrylic",1.19*g/cm3,3);
    mat_acrylic->AddElement(el_h,8);
    mat_acrylic->AddElement(el_c,5);
	mat_acrylic->AddElement(el_o,2);

	//Optical Properites of Acrylic
	G4MaterialPropertiesTable* acrylicMPT = new G4MaterialPropertiesTable();

	acrylicMPT->AddProperty("RINDEX",acrylicEnergies,acrylicRefractiveIndex,nEntries);
	//SiO2MPT->AddProperty("ABSLENGTH",SiO2AbsorptionEnergy,SiO2AbsorptionLength,2);
	//SiO2MPT->AddConstProperty("FASTTIMECONSTANT",20.*ns);
	//SiO2MPT->AddConstProperty("SLOWTIMECONSTANT",45.*ns);
	//SiO2MPT->AddConstProperty("YIELDRATIO",1.0);
	//SiO2MPT->AddConstProperty("SCINTILLATIONYIELD",100./MeV);

	mat_acrylic->SetMaterialPropertiesTable(acrylicMPT);

	

    //Silicon Nitride
    G4Element* el_n = new G4Element("Nitrogen", "N", 7,14.007*g/mole);
    G4Material* mat_si3n4 = new G4Material("Si3N4",3.17*g/cm3,2);
    mat_si3n4->AddElement(el_si,3);
    mat_si3n4->AddElement(el_n,4);

	//Optical Properites of Si3N4
	G4MaterialPropertiesTable* Si3N4MPT = new G4MaterialPropertiesTable();

	Si3N4MPT->AddProperty("RINDEX",Si3N4PhotonEnergies,Si3N4RefractiveIndex,nEntries);
	//Si3N4MPT->AddProperty("ABSLENGTH",SiO2AbsorptionEnergy,SiO2AbsorptionLength,2);
	//Si3N4MPT->AddConstProperty("FASTTIMECONSTANT",20.*ns);
	//Si3N4MPT->AddConstProperty("SLOWTIMECONSTANT",45.*ns);
	//Si3N4MPT->AddConstProperty("YIELDRATIO",1.0);
	//Si3N4MPT->AddConstProperty("SCINTILLATIONYIELD",100./MeV);

	mat_si3n4->SetMaterialPropertiesTable(Si3N4MPT);
	

    // Lead
    nistManager->FindOrBuildMaterial("G4_Pb");

	G4MaterialPropertiesTable *MPT_Pb = new G4MaterialPropertiesTable();
	MPT_Pb->AddProperty("RINDEX", EN, PbRI, NUM);
	MPT_Pb->AddProperty("EFFICIENCY", EQEEnergy,EQE, nEQE);
	G4Material::GetMaterial("G4_Pb")->SetMaterialPropertiesTable(MPT_Pb);

    // Vacuum "Air with low density"
    // G4Material* air = G4Material::GetMaterial("G4_AIR");
    // G4double density = 1.0e-5*air->GetDensity();
    // nistManager
    //   ->BuildMaterialWithNewDensity("Air_lowDensity", "G4_AIR", density);
    
    G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
    G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

void DetectorConstruction::zPos(G4double pos)
{
	fzPos = pos;
	boxPhysical->SetTranslation(G4ThreeVector(0,0,fzPos));
	G4RunManager::GetRunManager()->ReinitializeGeometry();
	G4cout << "zPos: " << pos << G4endl;
}

void DetectorConstruction::filenameChange(G4String file){
	filename = file;
	G4RunManager::GetRunManager()->ReinitializeGeometry();
	G4cout << "New filename: " << filename << endl;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
