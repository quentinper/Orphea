// Interaction simple : ajoute une classe active sur appui/touch
const whites = document.querySelectorAll('.white');
const blacks = document.querySelectorAll('.black');
//const musicNotes = document.getElementById();
const alim1 = document.getElementById("V3_3");
const alim2 = document.getElementById("V5");
const alim3 = document.getElementById("V9");
const alim4 = document.getElementById("V12");
const alim5 = document.getElementById("V24");
function bindKey(el) {
  el.addEventListener('pointerdown', e => { e.preventDefault(); el.classList.add('active'); });
  window.addEventListener('pointerup', () => el.classList.remove('active'));
  // tactile : remove on cancel/leave
  el.addEventListener('pointercancel', () => el.classList.remove('active'));
}

whites.forEach(bindKey);
blacks.forEach(bindKey);

// Petit dictionnaire pour convertir vos data-note en numéros MIDI
const noteToMidi = {
  "C1": 61, "C1#": 62, "D1": 63, "D1#": 64, "E1": 65, "F1": 66, "F1#": 67, "G1": 68, "G1#": 69, "A1": 70, "A1#": 71, "B1": 72,
  "C2": 73, "C2#": 74, "D2": 75, "D2#": 76, "E2": 77, "F2": 78, "F2#": 79, "G2": 80, "G2#": 81, "A2": 82, "A2#": 83, "B2": 84
};

async function sendMidiNote(noteName, isPressed) {
  const status = isPressed ? 0x90 : 0x80; // Note On ou Note Off
  const note = noteToMidi[noteName] || 0;
  const velocity = isPressed ? 100 : 0;   // Velocity fixe à 100 ou 0

  await fetch('/api/keypressed', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ 
      s: status, 
      n: note, 
      v: velocity 
    })
  });
}

// Mise à jour de la fonction bindKey
function bindKey(el) {
  el.addEventListener('pointerdown', e => {
    e.preventDefault();
    el.classList.add('active');
    sendMidiNote(el.dataset.note, true);
  });

  // Envoi du Note Off (velocity 0) quand on relâche
  const release = () => {
    if (el.classList.contains('active')) {
      el.classList.remove('active');
      sendMidiNote(el.dataset.note, false);
    }
  };

  window.addEventListener('pointerup', release);
  el.addEventListener('pointercancel', release);
}

























// support clavier : highlight via space/enter for focused element
document.addEventListener('keydown', e => {
  if (e.code === 'Space' || e.code === 'Enter') {
    const el = document.querySelector('.white');
    if (el) el.classList.add('active');
  }
});
document.addEventListener('keyup', () => {
  document.querySelectorAll('.white.active, .black.active').forEach(k => k.classList.remove('active'));
});
//boutons effets
function addEffectBehavior(id) {
  const btn = document.getElementById(id);

  btn.style.position = "relative";  // pour contenir la flamme

  btn.addEventListener("click", () => {

    /* --- Création de la flamme LED --- */
    const flame = document.createElement("div");
    flame.classList.add("flame");
    btn.appendChild(flame);

    setTimeout(() => flame.remove(), 1000); // durée de la flamme

    /* --- Changement de couleur du bouton --- */
    btn.classList.remove("w3-red");
    btn.classList.add("w3-green");

    setTimeout(() => {
      btn.classList.remove("w3-green");
      btn.classList.add("w3-red");
    }, 1000);
  });
}

["Eff1", "Eff2", "Eff3", "Eff4"].forEach(addEffectBehavior);



whites.forEach(key => {
  key.addEventListener("pointerdown", () => {
    console.log("Touche blanche : " + key.dataset.note);
    // 👉 Ici tu mets ton action
  });
});

blacks.forEach(key => {
  key.addEventListener("pointerdown", () => {
    console.log("Touche noire : " + key.dataset.note);
    // 👉 Ici tu mets ton action
  });
});

// name = "V3_3", "V5", "V9", "V12", "V15", "V24"
// present = true (vert) ou false (rouge)
function updateVoltage(name, present) {
  const led = document.getElementById(name);
  if (!led) {
    return;
  }

  led.classList.remove("on", "off");

  if (present) {
    led.classList.add("on");
  }
  else {
    led.classList.add("off");
  }
}

// Exemple : test manuel (à supprimer ensuite)
let vrai = true;

setInterval(() => {
  if (vrai) {
    updateVoltage("V3_3", true);
    updateVoltage("V5", true);
    updateVoltage("V9", false);
    updateVoltage("V12", true);
    updateVoltage("V24", false);
  }
  else {
    updateVoltage("V3_3", false);
    updateVoltage("V5", false);
    updateVoltage("V9", true);
    updateVoltage("V12", false);
    updateVoltage("V24", true);
  }

  vrai = !vrai; // alterne l’état à chaque seconde
}, 1000); // 1000 ms = 1 seconde

function updatePreload(musicName, totalNotes, noteIndex, percentage) {
  document.getElementById("musicName").textContent = musicName;
  document.getElementById("totalNotes").textContent = totalNotes;
  document.getElementById("currentNote").textContent = noteIndex;
  document.getElementById("percent").textContent = percentage + "%";
  document.getElementById("progressBar").style.width = percentage + "%";
}

let totalNotesSim = 3;
let currentNoteSim = 1;
let percentSim = 0;

setInterval(() => {
  if (currentNoteSim > totalNotesSim) {
    return;
  }

  updatePreload(
    "Exemple : Melody-01",
    totalNotesSim,
    currentNoteSim,
    percentSim
  );


  percentSim += 10;


  if (percentSim > 100) {
    percentSim = 0;
    currentNoteSim++;
  }
}, 80);


// ------------------------
// JS : Série de fetch
// ------------------------


// Récupérer l'état des alimentations
async function getAlimentations() {
  const res = await fetch('/api/alims');
  return await res.json();
}

async function jsonAlim() {
  try {
    // Appeler la fonction pour obtenir le JSON
    const alimentations = await getAlimentations();
    const alim1 = alimentations.alim1;  // Valeur de "alim1"
    const alim2 = alimentations.alim2;  // Valeur de "alim2"
    const alim3 = alimentations.alim3;  // Valeur de "alim3"
    const alim4 = alimentations.alim4;  // Valeur de "alim4"
    const alim5 = alimentations.alim5;  // Valeur de "alim5"
  }
  catch (error) {
    console.error("Erreur lors de la récupération des alimentations:", error);
  }
}

jsonAlim();

// Envoyer les solénoïdes appuyés
async function sendSolenoids(solenoidStates) {
  await fetch('/api/solenoids', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ solenoids: solenoidStates })
  });
}


// Récupérer les effets appuyés
async function getEffects() {
  const res = await fetch('/api/effects');
  return await res.json();
}


// Exemple d'utilisation
test();
async function test() {
  const alim = await getAlimentations();
  console.log('Alim:', alim);


  await sendSolenoids([1, 0, 1, 0]);
  console.log('Solénoïdes envoyés');


  const effects = await getEffects();
  console.log('Effets:', effects);
}