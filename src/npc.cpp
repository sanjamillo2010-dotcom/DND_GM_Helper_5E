#include "../include/npc.h"

namespace DND_GM_Helper_5E {
namespace NPC {

NPC::NPC(QString iPrenom, QString iNom, QString iRace,
         QString iApparence, QString iApparence_Descripion, int iApparence_Index,
         QString iPersonnalite, QString iPersonnalite_Descripion, int iPersonnalite_Index,
         QString iMotivation, QString iMotivation_Descripion, int iMotivation_Index,
         QString iAccroche, QString iAccroche_Descripion, int iAccroche_Index)
{
    Prenom = iPrenom;
    Nom = iNom;
    Race = iRace;

    Apparence = iApparence;
    Apparence_Descripion = iApparence_Descripion;
    Apparence_Index = iApparence_Index;

    Personnalite = iPersonnalite;
    Personnalite_Descripion = iPersonnalite_Descripion;
    Personnalite_Index = iPersonnalite_Index;

    Motivation = iMotivation;
    Motivation_Descripion = iMotivation_Descripion;
    Motivation_Index = iMotivation_Index;

    Accroche = iAccroche;
    Accroche_Descripion = iAccroche_Descripion;
    Accroche_Index = iAccroche_Index;
}

void NPC::Set_Random_Race() {
    int Rand = Utils::Utils::Rand_int(1 , 14);
    switch (Rand)
    {
    case 1:
        Race = "Haut-elfe";
        break;

    case 2:
        Race = "Elfe des bois";
        break;

    case 3:
        Race = "Elfe noir";
        break;

    case 4:
        Race = "Halfelin pied-leger";
        break;

    case 5:
        Race = "Halfling robuste";
        break;

    case 6:
        Race = "Humain";
        break;

    case 7:
        Race = "Nain des colline";
        break;

    case 8:
        Race = "Nain des montagnes";
        break;

    case 9:
        Race = "Demi-elfe";
        break;

    case 10:
        Race = "Demi-orc";
        break;

    case 11:
        Race = "Drakeide";
        break;

    case 12:
        Race = "Gnome des forets";
        break;

    case 13:
        Race = "Gnome des rochs";
        break;

    case 14:
        Race = "Tieffelin";
        break;
    }
}

void NPC::Set_Random_Prenom(QString Race) {
    QStringList Prenoms;

    if (Race == "Haut-elfe" ||
        Race == "Elfe des bois" ||
        Race == "Elfe noir")
    {
        Prenoms = {
            "Aelar",
            "Aelwen",
            "Arannis",
            "Caelynn",
            "Erevan",
            "Faelar",
            "Lia",
            "Luthien",
            "Naeris",
            "Sylvar",
            "Thalion",
            "Vaelis",
            "Yavanna",
            "Zelphar"
        };
    }

    else if (Race == "Halfelin pied-leger" ||
             Race == "Halfling robuste")
    {
        Prenoms = {
            "Alton",
            "Cade",
            "Corrin",
            "Eldon",
            "Finnan",
            "Lyle",
            "Milo",
            "Osborn",
            "Perrin",
            "Rollo",
            "Roscoe",
            "Sam",
            "Tobin",
            "Willem"
        };
    }

    else if (Race == "Humain")
    {
        Prenoms = {
            "Aric",
            "Bastien",
            "Cedric",
            "Damien",
            "Edric",
            "Gaspard",
            "Hugo",
            "Julien",
            "Lucien",
            "Martin",
            "Nicolas",
            "Pierre",
            "Théo",
            "Victor"
        };
    }

    else if (Race == "Nain des colline" ||
             Race == "Nain des montagnes")
    {
        Prenoms = {
            "Balin",
            "Borin",
            "Dain",
            "Dorin",
            "Durin",
            "Gimli",
            "Gloin",
            "Kili",
            "Nori",
            "Oin",
            "Thorin",
            "Thrain",
            "Varin",
            "Vondal"
        };
    }

    else if (Race == "Demi-elfe")
    {
        Prenoms = {
            "Aeron",
            "Alaric",
            "Elian",
            "Elyas",
            "Kael",
            "Lorien",
            "Maelis",
            "Nym",
            "Riven",
            "Sylas",
            "Theren",
            "Vael",
            "Wren",
            "Zaren"
        };
    }

    else if (Race == "Demi-orc")
    {
        Prenoms = {
            "Brug",
            "Drog",
            "Gor",
            "Grom",
            "Gruk",
            "Karg",
            "Mog",
            "Ragash",
            "Rogar",
            "Shak",
            "Thok",
            "Ugar",
            "Varg",
            "Zog"
        };
    }

    else if (Race == "Drakeide")
    {
        Prenoms = {
            "Arjhan",
            "Balasar",
            "Ghesh",
            "Heskan",
            "Kriv",
            "Medrash",
            "Mehen",
            "Nadarr",
            "Patrin",
            "Rhogar",
            "Shamash",
            "Tarhun",
            "Torinn",
            "Akra"
        };
    }

    else if (Race == "Gnome des forets" ||
             Race == "Gnome des rochs")
    {
        Prenoms = {
            "Alston",
            "Boddynock",
            "Brocc",
            "Dimble",
            "Eldon",
            "Fibblestib",
            "Fonkin",
            "Gimble",
            "Namfoodle",
            "Roondar",
            "Schnipper",
            "Sindri",
            "Warryn",
            "Zook"
        };
    }

    else if (Race == "Tieffelin")
    {
        Prenoms = {
            "Akmenos",
            "Amnon",
            "Barakas",
            "Damakos",
            "Ekemon",
            "Kairon",
            "Leucis",
            "Melech",
            "Morthos",
            "Pelaios",
            "Skamos",
            "Therai",
            "Zariel",
            "Zevlor"
        };
    }

    if (!Prenoms.isEmpty())
    {
        int Rand = Utils::Utils::Rand_int(0, Prenoms.size() - 1);
        Prenom = Prenoms[Rand];
        std::cout << Prenom.toStdString() << std::endl;
    }
}

void NPC::Set_Random_Name(QString Race) {
    QStringList Noms;

    if (Race == "Haut-elfe" ||
        Race == "Elfe des bois" ||
        Race == "Elfe noir")
    {
        Noms = {
            "Luneclair",
            "Feuillesombre",
            "Étoilechantante",
            "Ventdargent",
            "Feuilledor",
            "Nuitargent",
            "Boisancien",
            "Chantelune",
            "Écorceverte",
            "Flèchefroide"
        };
    }

    else if (Race == "Halfelin pied-leger" ||
             Race == "Halfling robuste")
    {
        Noms = {
            "Piedléger",
            "Longuebarbe",
            "Bonrepas",
            "Feuillou",
            "Petitpas",
            "Vertpré",
            "Bonpain",
            "Jolicoeur",
            "Roulebois",
            "Souscolline"
        };
    }

    else if (Race == "Humain")
    {
        Noms = {
            "Martin",
            "Dubois",
            "Leroy",
            "Moreau",
            "Durand",
            "Lambert",
            "Fontaine",
            "Mercier",
            "Renaud",
            "Beaumont"
        };
    }

    else if (Race == "Nain des colline" ||
             Race == "Nain des montagnes")
    {
        Noms = {
            "Barbefer",
            "Poingacier",
            "Marteaufort",
            "Barbeflamme",
            "Hachebrune",
            "Forgepierre",
            "Rocheprofonde",
            "Barberoc",
            "Bouclierfer",
            "Brisecrâne"
        };
    }

    else if (Race == "Demi-elfe")
    {
        Noms = {
            "Lunevoie",
            "Ventdoux",
            "Étoileverte",
            "Boisclair",
            "Aubétoile",
            "Feuillelune",
            "Ventelune",
            "Clairbois",
            "Nuitverte",
            "Chantvent"
        };
    }

    else if (Race == "Demi-orc")
    {
        Noms = {
            "Brisecrâne",
            "Poingvert",
            "Dentrouge",
            "Hachebrutale",
            "Peau-de-fer",
            "Sangnoir",
            "Œilrouge",
            "Crocdacier",
            "Mainlourde",
            "Hurleguerre"
        };
    }

    else if (Race == "Drakeide")
    {
        Noms = {
            "Flammeécaille",
            "Croc-de-feu",
            "Écaille-dorée",
            "Souffleardent",
            "Griffe-noire",
            "Écaille-de-fer",
            "Flammeargent",
            "Croc-ancien",
            "Écaillerouge",
            "Sang-de-dragon"
        };
    }

    else if (Race == "Gnome des forets" ||
             Race == "Gnome des rochs")
    {
        Noms = {
            "Bricolevis",
            "Rouagefol",
            "Tournécrou",
            "Petiteroue",
            "Fouineboulon",
            "Grinchevis",
            "Cliquetis",
            "Pignonvert",
            "Bidouille",
            "Rouleécrou"
        };
    }

    else if (Race == "Tieffelin")
    {
        Noms = {
            "Sombrefeu",
            "Cendreflamme",
            "Nuitrouge",
            "Corne-noire",
            "Sangombre",
            "Flamme-sombre",
            "Cœurdebraise",
            "Ombreflamme",
            "Feunoir",
            "Épine-rouge"
        };
    }

    if (!Noms.isEmpty())
    {
        int Rand = Utils::Utils::Rand_int(0, Noms.size() - 1);
        Nom = Noms[Rand];
    }
}

void NPC::Set_Random_Apparence() {
    Apparence_Index = Utils::Utils::Rand_int(1, 20);

    switch (Apparence_Index)
    {
    case 1:
        Apparence = "Balafré";
        Apparence_Descripion = "Cicatrice impressionnante, morsure de loup, lèvres entaillées";
        break;

    case 2:
        Apparence = "Élégant";
        Apparence_Descripion = "Vêtements de qualité, posture impeccable, trop raffiné pour les lieux";
        break;

    case 3:
        Apparence = "Crasseux";
        Apparence_Descripion = "Odeur désagréable, vêtements en lambeaux, ongles noirs de crasse";
        break;

    case 4:
        Apparence = "Fantômatique";
        Apparence_Descripion = "Silencieux, se fond dans le décor, on l'oublie instantanément";
        break;

    case 5:
        Apparence = "Imposant";
        Apparence_Descripion = "Stature massive, voix tonitruante, doit se baisser pour passer les portes";
        break;

    case 6:
        Apparence = "Flamboyant";
        Apparence_Descripion = "Couleurs criardes, bijoux clinquants, parfum entêtant";
        break;

    case 7:
        Apparence = "Usé";
        Apparence_Descripion = "Rides profondes, dos voûté, mains calleuses";
        break;

    case 8:
        Apparence = "Juvénile";
        Apparence_Descripion = "Traits enfantins, énergie débordante, voix claire et aiguë";
        break;

    case 9:
        Apparence = "Exotique";
        Apparence_Descripion = "Accent marqué, vêtements d'ailleurs, traits inhabituels";
        break;

    case 10:
        Apparence = "Encapuchonné";
        Apparence_Descripion = "Visage dans l'ombre, cape à capuche, on ne voit que ses yeux";
        break;

    case 11:
        Apparence = "Blessé";
        Apparence_Descripion = "Bandage sanglant, grimace de douleur, boite";
        break;

    case 12:
        Apparence = "Contradictoire";
        Apparence_Descripion = "Noble aux mains calleuses, guerrier érudit, prêtre armé jusqu'aux dents";
        break;

    case 13:
        Apparence = "Tatoué";
        Apparence_Descripion = "Encre couvrant bras et cou, symboles tribaux, marques rituelles";
        break;

    case 14:
        Apparence = "Maniéré";
        Apparence_Descripion = "Gestes précis et calculés, posture parfaite, ton soutenu";
        break;

    case 15:
        Apparence = "Hirsute";
        Apparence_Descripion = "Barbe sauvage, cheveux emmêlés, sourcils broussailleux";
        break;

    case 16:
        Apparence = "Parfait";
        Apparence_Descripion = "Beauté troublante, symétrie dérangeante, peau sans défaut";
        break;

    case 17:
        Apparence = "Prothétique";
        Apparence_Descripion = "Bras mécanique, œil de verre, jambe de bois sculptée";
        break;

    case 18:
        Apparence = "Bestial";
        Apparence_Descripion = "Griffes sous les ongles, dents pointues, regard sauvage";
        break;

    case 19:
        Apparence = "Maladif";
        Apparence_Descripion = "Toux persistante, peau grisâtre, mains tremblantes";
        break;

    case 20:
        Apparence = "Changeant";
        Apparence_Descripion = "Apparence changeante, traits flous, impression étrange";
        break;
    }
}

void NPC::Set_Random_Personnalite() {
    Personnalite_Index = Utils::Utils::Rand_int(1, 20);

    switch (Personnalite_Index)
    {
    case 1:
        Personnalite = "Anxieux";
        Personnalite_Descripion = "Il s'inquiète facilement et semble constamment sous pression.";
        break;

    case 2:
        Personnalite = "Optimiste";
        Personnalite_Descripion = "Il reste positif et cherche toujours le bon côté des choses.";
        break;

    case 3:
        Personnalite = "Cynique";
        Personnalite_Descripion = "Il se montre sarcastique et doute généralement des intentions des autres.";
        break;

    case 4:
        Personnalite = "Protecteur";
        Personnalite_Descripion = "Il veille naturellement sur les personnes qui l'entourent.";
        break;

    case 5:
        Personnalite = "Arrogant";
        Personnalite_Descripion = "Il se croit supérieur et supporte difficilement qu'on l'interrompe.";
        break;

    case 6:
        Personnalite = "Timide";
        Personnalite_Descripion = "Il parle peu, évite les regards et préfère rester discret.";
        break;

    case 7:
        Personnalite = "Calculateur";
        Personnalite_Descripion = "Il analyse attentivement les situations avant de prendre une décision.";
        break;

    case 8:
        Personnalite = "Impulsif";
        Personnalite_Descripion = "Il agit rapidement et laisse souvent ses émotions décider à sa place.";
        break;

    case 9:
        Personnalite = "Mélancolique";
        Personnalite_Descripion = "Il reste nostalgique du passé et évoque régulièrement de vieux souvenirs.";
        break;

    case 10:
        Personnalite = "Obsessionnel";
        Personnalite_Descripion = "Il recherche constamment la perfection et revient sans cesse sur les détails.";
        break;

    case 11:
        Personnalite = "Charmeur";
        Personnalite_Descripion = "Il est sociable, séduisant et utilise facilement son charme.";
        break;

    case 12:
        Personnalite = "Stoïque";
        Personnalite_Descripion = "Il montre très peu ses émotions et garde son calme en toute circonstance.";
        break;

    case 13:
        Personnalite = "Nerveux";
        Personnalite_Descripion = "Il semble constamment tendu et réagit facilement aux événements.";
        break;

    case 14:
        Personnalite = "Pédant";
        Personnalite_Descripion = "Il corrige volontiers les autres et insiste sur les détails.";
        break;

    case 15:
        Personnalite = "Mystique";
        Personnalite_Descripion = "Il parle de phénomènes étranges, de prophéties ou de forces mystérieuses.";
        break;

    case 16:
        Personnalite = "Bourru";
        Personnalite_Descripion = "Il parle peu et répond souvent de manière sèche ou agressive.";
        break;

    case 17:
        Personnalite = "Enthousiaste";
        Personnalite_Descripion = "Il déborde d'énergie et communique facilement son enthousiasme.";
        break;

    case 18:
        Personnalite = "Dépressif";
        Personnalite_Descripion = "Il se montre pessimiste et semble avoir perdu une partie de sa motivation.";
        break;

    case 19:
        Personnalite = "Complotiste";
        Personnalite_Descripion = "Il voit des complots et des intentions cachées dans de nombreux événements.";
        break;

    case 20:
        Personnalite = "Adaptable";
        Personnalite_Descripion = "Il modifie facilement son comportement selon la personne à laquelle il parle.";
        break;
    }
}

void NPC::Set_Random_Motivation() {
    Motivation_Index = Utils::Utils::Rand_int(1, 20);

    switch (Motivation_Index)
    {
    case 1:
        Motivation = "Rédemption";
        Motivation_Descripion = "Il cherche à réparer une faute importante de son passé.";
        break;

    case 2:
        Motivation = "Vengeance";
        Motivation_Descripion = "Il poursuit quelqu'un à cause d'un ancien tort.";
        break;

    case 3:
        Motivation = "Protection";
        Motivation_Descripion = "Il cherche à protéger une personne ou quelque chose.";
        break;

    case 4:
        Motivation = "Ambition";
        Motivation_Descripion = "Il veut gravir les échelons et obtenir davantage de pouvoir.";
        break;

    case 5:
        Motivation = "Fuite";
        Motivation_Descripion = "Il cherche à échapper à son passé ou à une identité dangereuse.";
        break;

    case 6:
        Motivation = "Cupidité";
        Motivation_Descripion = "Il souhaite accumuler toujours davantage de richesses.";
        break;

    case 7:
        Motivation = "Amour";
        Motivation_Descripion = "Il est profondément attaché à quelqu'un.";
        break;

    case 8:
        Motivation = "Espionnage";
        Motivation_Descripion = "Il rapporte discrètement des informations à une autre personne.";
        break;

    case 9:
        Motivation = "Serment";
        Motivation_Descripion = "Il est déterminé à respecter une promesse qu'il a faite.";
        break;

    case 10:
        Motivation = "Survie";
        Motivation_Descripion = "Il agit avec un objectif simple : rester en vie.";
        break;

    case 11:
        Motivation = "Révolution";
        Motivation_Descripion = "Il souhaite renverser l'ordre ou le pouvoir actuellement établi.";
        break;

    case 12:
        Motivation = "Dette";
        Motivation_Descripion = "Il doit quelque chose à quelqu'un et cherche à régler cette dette.";
        break;

    case 13:
        Motivation = "Savoir";
        Motivation_Descripion = "Il recherche une connaissance particulière, interdite ou non.";
        break;

    case 14:
        Motivation = "Immortalité";
        Motivation_Descripion = "Il cherche un moyen de vivre éternellement.";
        break;

    case 15:
        Motivation = "Prophétie";
        Motivation_Descripion = "Il agit parce qu'il croit devoir accomplir une prophétie.";
        break;

    case 16:
        Motivation = "Addiction";
        Motivation_Descripion = "Il est dépendant d'une substance, d'un jeu ou d'une autre habitude.";
        break;

    case 17:
        Motivation = "Nihilisme";
        Motivation_Descripion = "Il souhaite voir disparaître ce qui l'entoure.";
        break;

    case 18:
        Motivation = "Famille";
        Motivation_Descripion = "Sa famille constitue la raison principale de ses actions.";
        break;

    case 19:
        Motivation = "Sacrifice";
        Motivation_Descripion = "Il accepte de se mettre en danger afin d'aider les autres.";
        break;

    case 20:
        Motivation = "Double-Vie";
        Motivation_Descripion = "Il mène deux existences différentes et incompatibles.";
        break;
    }
}

void NPC::Set_Random_Accroche() {
    Accroche_Index = Utils::Utils::Rand_int(1, 20);

    switch (Accroche_Index)
    {
    case 1:
        Accroche = "Reconnaissance";
        Accroche_Descripion = "Il prétend connaître l'un des personnages.";
        break;

    case 2:
        Accroche = "Objet";
        Accroche_Descripion = "Il possède ou transporte un objet lié à l'un des personnages.";
        break;

    case 3:
        Accroche = "Urgence";
        Accroche_Descripion = "Il annonce qu'une situation urgente nécessite leur attention.";
        break;

    case 4:
        Accroche = "Témoin";
        Accroche_Descripion = "Il a assisté à un événement important pour les personnages.";
        break;

    case 5:
        Accroche = "Marché";
        Accroche_Descripion = "Il propose une offre qui semble intéressante mais peut cacher quelque chose.";
        break;

    case 6:
        Accroche = "Avertissement";
        Accroche_Descripion = "Il avertit le groupe d'une menace ou d'un danger imminent.";
        break;

    case 7:
        Accroche = "Information Gratuite";
        Accroche_Descripion = "Il fournit spontanément une information qui pourrait leur être utile.";
        break;

    case 8:
        Accroche = "Sosie";
        Accroche_Descripion = "Il ressemble suffisamment à quelqu'un d'important pour attirer l'attention.";
        break;

    case 9:
        Accroche = "Mauvais Timing";
        Accroche_Descripion = "Il arrive à un moment particulièrement mal choisi.";
        break;

    case 10:
        Accroche = "Cadeau Piégé";
        Accroche_Descripion = "Il offre un objet ou une aide qui risque de provoquer davantage d'ennuis.";
        break;

    case 11:
        Accroche = "Prophétie";
        Accroche_Descripion = "Il annonce une vision concernant l'un des personnages ou leur avenir.";
        break;

    case 12:
        Accroche = "Parent";
        Accroche_Descripion = "Il affirme avoir un lien familial avec l'un des personnages.";
        break;

    case 13:
        Accroche = "Suicide";
        Accroche_Descripion = "Il demande désespérément l'aide du groupe avant qu'il ne soit trop tard.";
        break;

    case 14:
        Accroche = "Vol";
        Accroche_Descripion = "Il vole quelque chose au groupe.";
        break;

    case 15:
        Accroche = "Coursier";
        Accroche_Descripion = "Il transmet un message ou une lettre destinée au groupe.";
        break;

    case 16:
        Accroche = "Accusation";
        Accroche_Descripion = "Il accuse publiquement le groupe d'une action.";
        break;

    case 17:
        Accroche = "Méprise";
        Accroche_Descripion = "Il confond l'un des personnages avec quelqu'un d'autre.";
        break;

    case 18:
        Accroche = "Agonie";
        Accroche_Descripion = "Il est mourant et demande de l'aide au groupe.";
        break;

    case 19:
        Accroche = "Chantage";
        Accroche_Descripion = "Il menace de révéler quelque chose afin d'obtenir ce qu'il veut.";
        break;

    case 20:
        Accroche = "Malédiction";
        Accroche_Descripion = "Il remet au groupe un objet portant une malédiction.";
        break;
    }
}

void NPC::Print_NPC_Debug() {
    std::cout << Prenom.toStdString() + " " + Nom.toStdString()
                + "\n" + Apparence.toStdString() + " : " + Apparence_Descripion.toStdString()
                + "\n" + Personnalite.toStdString() + " : " + Personnalite_Descripion.toStdString()
                + "\n" + Motivation.toStdString() + " : " + Motivation_Descripion.toStdString()
                + "\n" + Accroche.toStdString() + " : " + Accroche_Descripion.toStdString() << std::endl;
}

} // namespace NPC
} // namespace DND_GM_Helper_5E
