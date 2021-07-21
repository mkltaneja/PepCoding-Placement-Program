import firebase from 'firebase/app';
import 'firebase/auth'
import 'firebase/storage'
import 'firebase/firestore'

firebase.initializeApp(
    {
        apiKey: "AIzaSyBIBuW7sBjvunuR4ge2qgEmRQgOoFzvGlA",
        authDomain: "project-1-85fc4.firebaseapp.com",
        projectId: "project-1-85fc4",
        storageBucket: "project-1-85fc4.appspot.com",
        messagingSenderId: "997215241154",
        appId: "1:997215241154:web:10eeac772322c6e0224c5b"
    }
);

export const auth  = firebase.auth();
const firestore = firebase.firestore();

export const database = {
    users: firestore.collection('users'),
    getCurrentTimeStamp : firebase.firestore.FieldValue.serverTimestamp
}

export const storage = firebase.storage();
export default firebase;