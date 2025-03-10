# **Mobile Application Development (OMC302)**

---

## **Chapter 1: Introduction to Android**
- **Definition & Importance:** Android is an open-source mobile operating system developed by Google.
- **Features of Android:**
  - Open-source
  - Customizable UI
  - Multi-tasking support
  - Extensive app marketplace (Google Play Store)
  - Strong security measures
- **Benefits:**
  - Large developer community
  - Cost-effective development
  - High market penetration
- **Android Architecture:**
  - **Linux Kernel:** Provides core functionalities like memory management, process control, security.
  - **Libraries:** SQLite, SSL, OpenGL, etc.
  - **Android Runtime (ART):** Runs applications in a managed environment.
  - **Application Framework:** Activity Manager, Content Providers, Location Manager, etc.
  - **Applications Layer:** Includes system apps like contacts, browser, and user-installed applications.

---

## **Chapter 2: Configuring Android Development Environment**
- **Development Tools:**
  - Android Studio (Official IDE)
  - Android SDK (Software Development Kit)
  - AVD (Android Virtual Device)
  - Gradle Build System
- **Installation Steps:**
  - Download & Install Android Studio
  - Configure SDK Manager
  - Set up Emulator or Real Device
- **Creating a New Project in Android Studio**
  - Selecting Project Template
  - Choosing Minimum SDK
  - Configuring Project Settings
- **Understanding Gradle in Android Development:**
  - **What is Gradle?**
    - Gradle is a powerful build automation tool used in Android development.
    - It manages dependencies, compiles source code, and packages the final APK/AAB.
  - **Gradle Build System:** Automates build processes and dependencies.
  - **Important Gradle Files:**
    - `build.gradle (Project Level)`: Configures repositories and dependencies.
    - `build.gradle (Module Level)`: Defines dependencies, SDK version, and build types.
    - `settings.gradle`: Includes project modules.
    - `gradle.properties`: Stores global Gradle properties.
    - `local.properties`: Stores local machine-specific configurations.

---

## **Chapter 3: Directory Structure and Important Files of Android Application**
- **Main Components:**
  - **Manifest File (`AndroidManifest.xml`)**
    - The `AndroidManifest.xml` file is a critical configuration file that provides essential information about the application to the Android system.
    - It declares:
      - App permissions (e.g., Internet, Location, Camera)
      - Application components (Activities, Services, Broadcast Receivers, Content Providers)
      - Intent filters
      - App themes and hardware/software requirements
  - **Java/Kotlin Source Files (`.java` or `.kt`)**
    - Contains app logic and business rules.
  - **Resource Directory (`res/`)**
    - `drawable/` (Images, Icons)
    - `layout/` (XML UI files)
    - `values/` (Strings, Colors, Styles, Dimensions)
  - **Gradle Scripts** (Dependency Management)
- **Important Folders in an Android Project:**
  - **`app/`**: Contains source code, resources, and build configurations.
  - **`gradle/`**: Contains Gradle wrapper files for build automation.
  - **`libs/`**: Stores additional libraries.
  - **`assets/`**: Holds raw files used in the app (e.g., fonts, JSON files).

---

## **Chapter 4: Activity and Intents**
- **Activities:**
  - Lifecycle: `onCreate()`, `onStart()`, `onResume()`, `onPause()`, `onStop()`, `onDestroy()`
  - Creating an Activity using `Activity` Class
- **Intents:**
  - Explicit Intent (Component-specific)
  - Implicit Intent (Requesting External Apps)
  - Passing Data between Activities

---

## **Chapter 5: Layout and Views**
- **Common Layouts:**
  - LinearLayout
  - RelativeLayout
  - ConstraintLayout
  - FrameLayout
- **UI Elements:**
  - TextView, EditText, Button, ImageView, RecyclerView, etc.
  - Event Listeners (OnClickListener, OnTouchListener, etc.)

---

## **Chapter 6: Menus, Action Bar, and Event Handling**
- **Menus:**
  - Options Menu
  - Context Menu
  - Popup Menu
- **Action Bar Customization:**
  - Adding Menu Items
  - Handling Actions
- **Event Handling:**
  - Handling Click, Long Click, Key Events

---

## **Chapter 7: Graphics and Files**
- **Graphics APIs:**
  - Canvas API
  - OpenGL ES
- **File Handling:**
  - Internal Storage
  - External Storage
  - Shared Preferences

---

## **Chapter 8: SQLite Database**
- **What is SQLite?**
  - SQLite is a lightweight relational database embedded in Android.
  - It allows applications to store and retrieve structured data locally without requiring a server.
- **Using SQLite in Android:**
  - **Creating a Database:**
    - Extend `SQLiteOpenHelper` class
    - Override `onCreate()` and `onUpgrade()` methods
  - **Performing CRUD Operations:**
    - `INSERT`, `SELECT`, `UPDATE`, `DELETE` using `SQLiteDatabase.execSQL()`
  - **Using `Cursor` to Fetch Data**
  - **Closing the Database Connection Properly**

---

## **Chapter 9: Android Tasks and Services**
- **Background Processing:**
  - AsyncTask (Deprecated)
  - WorkManager (Recommended)
- **Types of Services:**
  - Foreground Service
  - Background Service
  - Bound Service

---

## **Chapter 10: Testing Android Applications**
- **Testing Frameworks:**
  - JUnit (Unit Testing)
  - Espresso (UI Testing)
- **Testing Strategies:**
  - Functional Testing
  - Performance Testing
  - Security Testing

---

## **Chapter 11: Publishing Android Applications**
- **Google Play Console Registration**
- **Preparing for Release:**
  - Code Optimization
  - Security Checks
- **Uploading APK/AAB File**
- **App Monetization:**
  - Ads (Google AdMob)
  - In-App Purchases

---

## **Difference Between Java and Kotlin**
| Feature       | Java | Kotlin |
|--------------|------|--------|
| Null Safety  | Prone to NullPointerExceptions | Built-in null safety |
| Conciseness  | More verbose | Less code, concise syntax |
| Coroutines   | No native support | Native support for async programming |
| Extension Functions | Not supported | Supported |
| Data Classes | Requires boilerplate | Built-in `data class` |
| Functional Programming | Limited | Fully supports FP features |

---

### **References**
1. Wei-Meng Lee, *Beginning Android 4 Application Development*, Wiley, 2014.
2. Pradeep Kothari, *Android Application Development Black Book*, Dreamtech Press, 2015.

