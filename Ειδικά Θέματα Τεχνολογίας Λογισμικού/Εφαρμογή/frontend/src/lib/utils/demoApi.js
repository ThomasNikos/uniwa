// In-browser stand-in for the Express backend (backend/app.js), so the site can be
// hosted as static files on GitHub Pages. Data lives in each visitor's localStorage.
// Demo admin account: admin / admin

const DB_KEY = 'comb-demo-db';

function load() {
	const saved = JSON.parse(localStorage.getItem(DB_KEY) || 'null');
	if (saved) return saved;
	return {
		users: [
			{
				username: 'admin',
				password: 'admin',
				email: 'admin@comb.gr',
				phone: '2100000000',
				address: 'Αιγάλεω',
				role: 'admin',
				created_at: new Date().toISOString()
			}
		],
		appointments: [],
		nextId: 1
	};
}

// @ts-ignore
function save(db) {
	localStorage.setItem(DB_KEY, JSON.stringify(db));
}

// @ts-ignore
function session(user) {
	return {
		user: { username: user.username, email: user.email, role: user.role },
		token: `demo.${btoa(encodeURIComponent(user.username))}`
	};
}

// @ts-ignore
export async function login({ username, password }) {
	const db = load();
	// @ts-ignore
	const user = db.users.find((u) => u.username === username);
	if (!user || user.password !== password) throw new Error('Λάθος στοιχεία σύνδεσης');
	return session(user);
}

// @ts-ignore
export async function register({ username, password, email, phone, address }) {
	const db = load();
	// @ts-ignore
	if (db.users.some((u) => u.username === username)) throw new Error('Username already exists');
	// @ts-ignore
	if (db.users.some((u) => u.email === email)) throw new Error('Email already exists');
	const user = {
		username,
		password,
		email,
		phone,
		address,
		role: 'user',
		created_at: new Date().toISOString()
	};
	db.users.push(user);
	save(db);
	return session(user);
}

// @ts-ignore
export async function bookAppointment({ username, date, employee, type }) {
	const db = load();
	const iso = new Date(date).toISOString();
	// @ts-ignore
	if (db.appointments.some((a) => a.date === iso && a.employee === employee)) {
		throw new Error('Η ώρα δεν είναι διαθέσιμη.');
	}
	const appointment = { id: db.nextId++, username, date: iso, employee, type };
	db.appointments.push(appointment);
	save(db);
	return appointment;
}

export async function getAdminAppointments() {
	const db = load();
	return (
		[...db.appointments]
			// @ts-ignore
			.sort((a, b) => b.date.localeCompare(a.date))
			// @ts-ignore
			.map(({ username, ...appointment }) => {
				// @ts-ignore
				const { password, role, ...user } = db.users.find((u) => u.username === username) || {
					username
				};
				return { appointment, user };
			})
	);
}
